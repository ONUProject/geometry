// Vladislav Samsonov Russia MIPT
#include <iostream>
#include <algorithm>
using namespace std;

struct point {
    int x,y;

    inline point () {}
    inline point (int x, int y) : x(x),y(y) {}
    inline static bool compByX (const point & p1, const point & p2) {
        return p1.x < p2.x;
    }
    inline static bool compByYX (const point & p1, const point & p2) {
        return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
    }
};

class Treap {
private:
    class treap {
    private:
        treap * l, * r;
        int prior;
        int key, orient, sum, maxsum;

        static void split (int x, int orient, treap * t, treap *& l, treap *& r) {
            if (!t) l=r=0;
            else if (x<t->key || (x==t->key && orient>t->orient)) split(x,orient,t->l,l,t->l),r=t;
            else split(x,orient,t->r,t->r,r),l=t;
            update_size(t);
        }

        static void merge (treap *& t, treap * l, treap * r) {
            if (!l || !r) t=l?l:r;
            else if (l->prior>r->prior) merge(l->r,l->r,r),t=l;
            else merge(r->l,l,r->l),t=r;
            update_size(t);
        }

        inline static void update_size (treap * t) {
            if (!t) return;
            t->sum = t->orient + get_sum(t->l) + get_sum(t->r);
            t->maxsum = t->orient + get_sum(t->l);
            if (t->maxsum < get_msum(t->l))
                t->maxsum = get_msum(t->l);
            if (t->maxsum < t->orient + get_sum(t->l) + get_msum(t->r))
                t->maxsum = t->orient + get_sum(t->l) + get_msum(t->r);
        }
    public:
        inline treap (int x, int o) : l(0),r(0),prior(rand()),key(x),orient(o),sum(o),maxsum(o) {}

        inline static int get_sum (const treap * t) {
            return (t) ? t->sum : 0;
        }

        inline static int get_msum (const treap * t) {
            return (t) ? t->maxsum : 0;
        }

        static void insert (treap *& t, int x, int orient) {
            treap * t1, * t2;
            split(x,orient,t,t1,t2);
            merge(t1,t1,new treap(x, orient));
            merge(t,t1,t2);
            update_size(t);
        }

        static void erase (treap *& t, int x, int orient) {
            if (t->key==x && t->orient==orient) {
                treap * tmp=t;
                merge(t,t->l,t->r);
                delete tmp;
            }
            else {
                if (x<t->key || (x==t->key && orient>t->orient)) erase(t->l,x,orient);
                else erase(t->r,x,orient);
            }
            update_size(t);
        }

        static void clear (const treap * t) {
            if (!t) return;
            clear(t->l);
            clear(t->r);
            delete t;
        }
    };
    treap * root;
public:
    inline Treap () : root(0) {}
    inline void insert_begin (int x) { treap::insert(root, x, 1); }
    inline void insert_end (int x) { treap::insert(root, x, -1); }
    inline void erase_begin (int x) { treap::erase(root, x, 1); }
    inline void erase_end (int x) { treap::erase(root, x, -1); }
    inline void clear () {
        treap::clear(root);
        root = 0;
    }
    inline int pom () const {
        return treap::get_msum(root);
    }
};

point points[100001];
Treap seg;
int A,B;
int maxCnt = 0;

void build (size_t l, size_t r) {
    for (size_t i=l;i<r;++i) {
        seg.insert_begin(points[i].y);
        seg.insert_end(points[i].y + B);
        if (maxCnt < seg.pom())
            maxCnt = seg.pom();
    }
}

void remove_point (const point & p) {
    seg.erase_begin(p.y);
    seg.erase_end(p.y + B);
}

void add_point (const point & p) {
    seg.insert_begin(p.y);
    seg.insert_end(p.y + B);
    if (maxCnt < seg.pom())
        maxCnt = seg.pom();
}

void solve (size_t n) {
    size_t l=0,r=0;
    for (;r<n;++r)
        if (points[r].x > points[0].x + A)
            break;
    build(l,r);
    while (r < n) {
        remove_point(points[l]);
        ++l;
        while (r < n && points[r].x <= points[l].x + A)
            add_point(points[r]), ++r;
    }
}

int main () {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    srand(13);
    cin>>A>>B;
    size_t n;
    cin>>n;
    for (size_t i=0;i<n;++i)
        cin>>points[i].x>>points[i].y;
    sort(points, points+n, point::compByX);
    solve(n);
    swap(A, B);
    seg.clear();
    solve(n);
    cout<<maxCnt<<endl;
    return 0;
}
