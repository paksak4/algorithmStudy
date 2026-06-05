#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <regex>
#include <stdexcept>
using namespace std;

enum TokenKind { TK_INT, TK_RETURN, TK_IDENT, TK_NUMBER, TK_ASSIGN, TK_SEMICOLON, TK_PLUS, TK_MINUS, TK_MUL, TK_DIV, TK_EOF };

struct Token
{
    TokenKind kind;
    string str;
    int val;
};

class Lexer 
{
    istringstream in;
    string s; 
    int pos;
    vector<Token> tokens;
    set<string> keywords = {"int", "return"};

public:
    Lexer(const string& src): in(src), pos(0) 
    {
        string code((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        s = code;
    }

    vector<Token> tokenize() 
    {
        while (pos < s.size()) 
        {
            if(isspace(s[pos])) 
            { 
                ++pos; 
                continue; 
            }
            if(s.compare(pos,3,"int")==0 && !isalnum(s[pos+3])) 
            { 
                tokens.push_back({TK_INT,"int"}); 
                pos+=3; 
                continue; 
            }
            if(s.compare(pos,6,"return")==0 && !isalnum(s[pos+6])) 
            { 
                tokens.push_back({TK_RETURN,"return"}); 
                pos+=6; 
                continue; 
            }
            if(isalpha(s[pos]) || s[pos]=='_') 
            {
                int st=pos; 
                while(isalnum(s[pos])||s[pos]=='_') 
                    ++pos;
                tokens.push_back({TK_IDENT, s.substr(st,pos-st)});
                continue;
            }
            if (isdigit(s[pos])) 
            {
                int val=0; 

                while(isdigit(s[pos])) 
                    val=val*10+s[pos++]-'0';
                
                tokens.push_back({TK_NUMBER,"",val}); 
                continue;
            }
            switch (s[pos]) 
            {
                case '=': 
                    tokens.push_back({TK_ASSIGN,"="}); 
                    break;
                case ';': 
                    tokens.push_back({TK_SEMICOLON,";"}); 
                    break;
                case '+': 
                    tokens.push_back({TK_PLUS,"+"}); 
                    break;
                case '-': 
                    tokens.push_back({TK_MINUS,"-"}); 
                    break;
                case '*': 
                    tokens.push_back({TK_MUL,"*"}); 
                    break;
                case '/': 
                    tokens.push_back({TK_DIV,"/"}); 
                    break;
                default: 
                    throw runtime_error("Invalid char");
            } 
            ++pos;
        }
        tokens.push_back({TK_EOF,""});
        return tokens;
    }
};

class Node
{ 
public:
    virtual ~Node(){} 
};

class Expr : public Node 
{
public:
};

class Num : public Expr 
{ 
public:
    int val; 
    Num(int v)
    : val(v) {} 
};

class Var : public Expr 
{ 
public:
    string name; 
    Var(const string& n)
    : name(n) {} 
};

class BinOp : public Expr 
{ 
public:
    char op; 
    Expr *lhs, *rhs; 
    BinOp(char o, Expr* l, Expr* r)
    : op(o), lhs(l), rhs(r) {} 
};

class Stmt : public Node 
{
public:
};

class Decl : public Stmt 
{ 
public:
    string name; 
    Decl(const string& n) 
    : name(n) {} 
};

class Assign : public Stmt 
{ 
public:
    string name; 
    Expr* expr; 
    Assign(const string&n, Expr*e) 
    : name(n), expr(e) {} 
};

class Ret : public Stmt 
{ 
public:
    Expr* expr; 
    Ret(Expr*e) 
    : expr(e) {} 
};

class Parser 
{
public:
    vector<Token> toks;
    int pos = 0;

    Parser(const vector<Token>& t) 
    : toks(t) {}

    Token& peek(int k = 0) 
    {
        return toks[pos + k];
    }

    Token next() 
    {
        return toks[pos++];
    }

    bool match(TokenKind k) 
    {
        if (peek().kind == k) 
        {
            next();
            return true;
        }
        return false;
    }

    void expect(TokenKind k) 
    {
        if (!match(k)) 
            throw runtime_error("Syntax error");
    }

    vector<Stmt*> parse() 
    {
        vector<Stmt*> stmts;
        while (peek().kind != TK_EOF) 
        {
            if (peek().kind == TK_INT) 
            {
                next();
                string var = peek().str;
                expect(TK_IDENT);
                expect(TK_SEMICOLON);
                stmts.push_back(new Decl(var));
            } 
            else if (peek().kind == TK_IDENT) 
            {
                string var = next().str;
                expect(TK_ASSIGN);
                Expr* e = parse_expr();
                expect(TK_SEMICOLON);
                stmts.push_back(new Assign(var, e));
            } 
            else if (peek().kind == TK_RETURN) 
            {
                next();
                Expr* e = parse_expr();
                expect(TK_SEMICOLON);
                stmts.push_back(new Ret(e));
            } 
            else 
            {
                throw runtime_error("Invalid statement");
            }
        }
        return stmts;
    }

    Expr* parse_expr() 
    {
        Expr* lhs = parse_term();
        while (peek().kind == TK_PLUS || peek().kind == TK_MINUS)
        {
            char op = (peek().kind == TK_PLUS) ? '+' : '-';
            next();
            Expr* rhs = parse_term();
            lhs = new BinOp(op, lhs, rhs);
        }
        return lhs;
    }

    Expr* parse_term() 
    {
        Expr* lhs = parse_factor();
        while (peek().kind == TK_MUL || peek().kind == TK_DIV) 
        {
            char op = (peek().kind == TK_MUL) ? '*' : '/';
            next();
            Expr* rhs = parse_factor();
            lhs = new BinOp(op, lhs, rhs);
        }
        return lhs;
    }

    Expr* parse_factor() 
    {
        if (peek().kind == TK_IDENT)
        {
            string n = next().str;
            return new Var(n);
        }
        if (peek().kind == TK_NUMBER) 
        {
            int v = next().val;
            return new Num(v);
        }
        throw runtime_error("Invalid factor");
    }
};


// 宣言と代入順・return順チェック, 変数の管理
class Checker 
{
public:
    set<string> declared;
    bool return_seen = false;
    void check(const vector<Stmt*>& v) 
    {
        for(int i = 0; i < v.size(); ++i) 
        {
            Decl* d;
            Assign* a;
            Ret* r;
            if((d = dynamic_cast<Decl*>(v[i]))) 
            {
                if(declared.count(d->name)) 
                    throw runtime_error("double declaration: " + d->name);
                declared.insert(d->name);
            } 
            else if((a = dynamic_cast<Assign*>(v[i]))) 
            {
                if(!declared.count(a->name)) 
                    throw runtime_error("undeclared: " + a->name);
                varcheck(a->expr);
            } 
            else if((r = dynamic_cast<Ret*>(v[i]))) 
            {
                if (i != v.size() - 1) 
                    throw runtime_error("return must be last");
                varcheck(r->expr);
                return_seen = true;
            }
        }
        if (!return_seen) 
            throw runtime_error("missing return");
    }
    void varcheck(Expr* e)
    {
        if(Var* v = dynamic_cast<Var*>(e))
        {
            if(!declared.count(v->name)) 
                throw runtime_error("undeclared: " + v->name);
        }
        else if(BinOp* b = dynamic_cast<BinOp*>(e))
        {
            varcheck(b->lhs); 
            varcheck(b->rhs);
        }
    }
};

// x86コード生成 (eax에 결과)
class Gen 
{
public:
    map<string, int> vars; 
    int varcnt = 0;
    ostringstream code;

    void gen(const vector<Stmt*>& v)
    {
        code << "section .text\n\tglobal _main\n_main:\n";
        for(auto s : v)
        {
            if(Decl* d = dynamic_cast<Decl*>(s))
            {
                newvar(d->name);
            }
            else if(Assign* a = dynamic_cast<Assign*>(s)) 
            {
                genexpr(a->expr);
                code << "\tmov [ebp-" << vars[a->name] * 4 << "], eax\n";
            }
            else if(Ret* r = dynamic_cast<Ret*>(s))
            {
                genexpr(r->expr);
                code << "\tret\n";
            }
        }
    }

    void newvar(const string& n)
    { 
        vars[n] = ++varcnt; 
    }

    void genexpr(Expr* e)
    {
        if (Num* n = dynamic_cast<Num*>(e)) 
        {
            code << "\tmov eax, " << n->val << "\n";
        }
        else if (Var* v = dynamic_cast<Var*>(e)) 
        {
            code << "\tmov eax, [ebp-" << vars[v->name] * 4 << "]\n";
        }
        else if (BinOp* b = dynamic_cast<BinOp*>(e)) 
        {
            genexpr(b->lhs);
            code << "\tpush eax\n";
            genexpr(b->rhs);
            code << "\tmov ebx, eax\n\tpop eax\n";
            if (b->op == '+') 
                code << "\tadd eax, ebx\n";
            if (b->op == '-') 
                code << "\tsub eax, ebx\n";
            if (b->op == '*') 
                code << "\timul eax, ebx\n";
            if (b->op == '/') 
                code << "\tcdq\n\tidiv ebx\n";
        }
    }
    string output() 
    { 
        return code.str(); 
    }
};

int main(void) 
{
    string src((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    try 
    {
        Lexer lex(src);
        auto toks = lex.tokenize();
        Parser parser(toks);
        auto stmts = parser.parse();
        Checker().check(stmts);
        Gen g; g.gen(stmts);
        cout << g.output();
    } 
    catch (exception& e) 
    {
        cerr << "コンパイルエラー: "<< e.what() << endl;
        return 1;
    }
    return 0;
}
