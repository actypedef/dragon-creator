// version: 1.0.0 @2021-11-5

#include <bits/stdc++.h>
using namespace std;

inline bool IsOk(char ch) {
  if ('a' <= ch && ch <= 'z') return true;
  if ('A' <= ch && ch <= 'Z') return true;
  if (isdigit(ch)) return true;
  if (ch == '_') return true;
  if (ch == '$') return true;
  return false;
}

set<string> keys;
inline bool Key(const string &s) {
  return keys.find(s) != keys.end();
}

inline void Init() {
  string ks[1001] = {
      "int", "vector", "map", "bits", "include", "stdc", "using", "namespace", "std", "bool",
      "inline", "register", "unsigned", "char", "getchar", "isdigit", "return",
      "main", "scanf", "printf", "do", "if", "string", "set", "find", "end", "define", "mt19937", "switch", "case",
      "for", "insert", "while", "EOF", "class", "private", "public", "protected", "size", "length", "true", "false",
      "continue", "break", "cin", "cout", "endl", "else", "struct", "enum", "begin", "const", "ifdef", "ifndef", "long",
      "new",
      "signed", "void", "uniform_int_distribution", "fread", "fwrite", "FILE", "static", "typedef", "first", "second",
      "pair",
      "push_back", "emplace_back", "push", "pop", "pop_back", "sort", "unique", "resize", "stack", "top", "lower_bound",
      "empty", "back",
      "swap", "freopen", "fclose", "stdin", "stdout", "make_pair", "auto",
      "bitset", "hash", "operator", "template", "typename", "noexcept", "default", "constexpr", "explicit", "reset",
      "flip", "test", "any", "all", "none", "count", "to_string",
      "to_ulong", "to_ullong", "float", "double", "char16_t", "char32_t", "wchar_t", "short", "function", "bind", "ref",
      "cref", "invoke",
      "assign", "CLOCKS_PER_SEC", "clock", "NULL", "nullptr", "time", "clock_t", "size_t", "time_t", "tm",
      "__VA_ARGS__",
      "initializer_list", "tuple", "make_tuple", "tie", "get", "tuple_cat", // <tuple> oOOo0O
      "max", "min", "clear", "greater", "less", "plus", "friend", "this", "puts", "memset", "sizeof", "boolalpha",
      "volatile",
      "goto", "__gcd", "__builtin_popcount", "__builtin_ctz", "__builtin_clz", "__builtin_ffs", "fill_n",
      "strlen", "strcat", "strcpy", "memcpy", "memmove", "shuffle", "random_shuffle", "front", "pop_front",
      "isupper", "islower", "isalnum", "isalpha", "rand", "strcmp", "compare", "push_front", "priority_queue", "queue",
      "deque"
  };
  const int T = 1000;
  for (int i = 0; i <= T; i++) if (!ks[i].empty()) keys.insert(ks[i]);
}

map<string, string> mp;

// mt19937 seed(chrono::steady_clock::now().time_since_epoch().count());
mt19937 seed((uint64_t) (new char));
#define Random(l, r) uniform_int_distribution<int64_t>(l, r)(seed)
inline string GetId(int x) {
  switch (x) {
    case 0: return (string) "🐉";
    case 1: return (string) "🐍";
    case 2: return (string) "🐲";
    default: return (string) "🐉";
  }
}

set<string> holder;
inline string Gen() {
  string now;
  int len = Random(5, 8);
  do {
    now = "";
    for (int i = 1; i <= len; i++) now += GetId(Random(0, 2));
    if (now[0] == '0') now = GetId(Random(0, 1)) + now;
  } while (holder.find(now) != holder.end());
  holder.insert(now);
  return now;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("dragon.cpp", "w", stdout);
  Init();
  string ans;
  string s, F;
  bool on = false;
  char ch;

  while (scanf("%c", &ch) != EOF) F += ch;

  int bras = 0;
  bool skiped = false;
  // for (char ch: F) {
  for (int i = 0; i < int(F.length()) && (ch = F[i], true); i++) {
    if (ch == '\\') {
      ans += ch;
      ans += F[i + 1];
      i++;
      continue;
    }

    if (ch == '\"' || ch == '\'') bras ^= 1;
    if (bras) {
      ans += ch;
      continue;
    }

    if (ch == '#' && (F[i + 1] == 'i' || F[i + 1] == 'p')) { // 跳过 include / pragma 行
      ans += ch;
      skiped = true;
      continue;
    }
    if (skiped && ch == '\n') {
      ans += ch;
      skiped = false;
      continue;
    }
    if (skiped) {
      ans += ch;
      continue;
    }

    if (IsOk(ch)) on = true, s += ch;
    else if (on) {
      if (isdigit(s[0]) || Key(s)) ans += s;
      else {
        if (mp.find(s) != mp.end()) ans += mp[s];
          // else mp[s] = "#" + to_string(++CNT), ans += mp[s];
        else mp[s] = Gen(), ans += mp[s];
      }
      ans += ch;
      on = false, s = "";
    } else {
      ans += ch;
    }
  }

  cout << ans << endl;
}
