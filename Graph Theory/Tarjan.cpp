const int maxn = ;
const int maxm = ;
int n, m;
struct Edge {
    int to, next;
}e[maxm];
int cnt, head[maxn];
int sz, dfn[maxn], low[maxn], vis[maxn];
int scc;
stack<int> stk;

void init() {
    scc = cnt = sz = 0;
    while(!stk.empty()) stk.pop();
    memset(vis, 0, sizeof vis);
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
}

void addedge(int u, int v) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++sz;
    vis[u] = 1;
    stk.push(u);
    for(int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v] && low[u] > dfn[v]) {
            low[u] = dfn[v];
        }
    }
    if(low[u] == dfn[u]) {
        scc++;
        while(!stk.empty()) {
            int id = stk.top();
            stk.pop();
            vis[id] = 0;
            if(id == u) break;
        }
    }
}
