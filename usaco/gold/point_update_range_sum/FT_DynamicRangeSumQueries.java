package usaco.gold.point_update_range_sum;
/**
Source: CSES
Problem url: https://cses.fi/problemset/task/1648/

Fenwick Tree is used here.

Time Complexity:
*/

import java.io.*;
import java.util.*;
import java.util.stream.*;
 
/**
    Nathan
*/
public class FT_DynamicRangeSumQueries {
    static class SumFenwickTree {
        long[] ft;
        long[] a;
        public SumFenwickTree(int n) {
            ft = new long[n+1];
            a = new long[n+1];
        }
        void set(int k, long u) { add(k, u - a[k]); }
        void add(int k, long u) {
            a[k] += u;
            for (; k < ft.length; k += lsone(k)) ft[k] += u;
        }
        long sum(int k) {
            long res = 0;
            for (; k > 0; k -= lsone(k)) res += ft[k];
            return res;
        }
        int lsone(int x) { return x & (-x); }
    }

    public static void solve(FastScanner io) throws Exception {
        int n = io.nextInt(), q = io.nextInt();
        SumFenwickTree ft = new SumFenwickTree(n);
        long[] x = new long[n+1];
        for (int i = 1; i <= n; i++) {
            x[i] = io.nextLong();
            ft.set(i, x[i]);
        }
        for (int i = 0; i < q; i++) {
            int t = io.nextInt();
            if (t == 1) {
                int k = io.nextInt(), u = io.nextInt();
                ft.set(k, u);
            }
            else if (t == 2) {
                int a = io.nextInt(), b = io.nextInt();
                io.println(ft.sum(b) - ft.sum(a-1));
            }
        }
    }

    /**
        MAIN
    */
    public static void main(String[] args) throws Exception {
        // FastScanner io = new FastScanner("usaco-problem-name"); // usaco
        FastScanner io = new FastScanner();
		int t = 1;
        // t = io.nextInt(); // t testcases
		while (t-->0) {
            solve(io);
        }
        io.close();
    }
 
    /**
        RESERVED INSTANCES
    */
    static int MOD = 1_000_000_007; // prime number
    static int oo = (int)1e9; // infinity number (int)
	static long INF = (long) 2e18; // infinity number
	static Random random = new Random();
 
	/**
		HELPER
	*/
 
    // ALGEBRA
	static long add(long a, long b) { return (a + b) % MOD; }
	static long subtract(long a, long b) { return ((a - b) % MOD + MOD) % MOD; }
	static long multiply(long a, long b) { return (a * b) % MOD; }
	static long exp(long base, long exp) { 
		long result = 1;
		while (exp > 0) {
			if ((exp & 1) == 1) result = multiply(result, base);
			base = multiply(base, base);
			exp >>=1;
		}
		return result;
	}
    static long abs(long x) { return Math.abs(x); }
    static int abs(int x) { return Math.abs(x); }
    static int sign(long x) { return x < 0 ? -1 : 1; }
 
    // NUMBER THEORY
    static int gcd(int a, int b) { 
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    static int lcm(int a, int b) { return a * b / gcd(a,b); }
    static int binpow(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b % 2 != 0)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    static boolean[] sieve(int n) {
        boolean[] prime = new boolean[n+1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        return prime;
    }
    static int[] primeFactorization(int n) {
        int[] prime = new int[n+1];
        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                prime[p]++;
                n /= p;
            }
        }
        if (n > 1) prime[n] = 1; // if n is a large prime
        return prime;
    }
 
    // ARRAY OPERATIONS
    static void swap(int a, int b) { int temp = a; a = b; b = temp; }
    static void swap(int[] a, int i, int j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; }
    static void shuffle(int[] a) { 
        int n = a.length;
        for (int i = 0; i < n; i++) {
            int ri = random.nextInt(n); // random index
            swap(a, i, ri);
        }
    }
    static <T> void reverse(List<T> x) { Collections.reverse(x); }
    static int max(int[] a) { Arrays.sort(a); return a[a.length-1]; }
    static long max(long[] a) { Arrays.sort(a); return a[a.length-1]; }

    // HASHING
    static String hash(int[] x) { return Arrays.toString(x); }
    static String hash(long[] x) { return Arrays.toString(x); }
    static <T> String hash(List<T> x) { return x.toString(); }
 
    // SORTING
    static void sort(int[] a) { Arrays.sort(a); }
    static void sort(long[] a) { Arrays.sort(a); }
    static <T extends Comparable<? super T>> void sort(List<T> a) { Collections.sort(a); }
    static void ruffleSort(int[] a) { shuffle(a); sort(a); }
 
    // FACTORIALS & nCk
	static long[] factorials = new long[2_000_005];
	static long[] inverseFactorials = new long[2_000_005];
	static void precomputeFactorials() {
        int n = factorials.length;
		factorials[0] = 1;
		for (int i = 1; i < factorials.length; i++) {
			factorials[i] = multiply(factorials[i-1], i);
		}
        inverseFactorials[n-1] = exp(factorials[n-1], MOD-2);
        for (int i = n-2; i >= 0; i--) {
            inverseFactorials[i] = multiply(inverseFactorials[i+1], i);
        }
	}
    static long nCk(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return multiply(factorials[n], multiply(inverseFactorials[n-k], inverseFactorials[k]));
    }

    // STRING
    static String repeat(String s, int count) { return s.repeat(count); }

    // BINARY SEARCH
    static int[] binarySearch(int x, int[] a) {
        // looking for transition point
        int l = -1, r = a.length-1;
        while (r - l > 1) {
            int mid = (l + r) >>> 1;
            if (x < a[mid]) r = mid;
            else l = mid;
        }
        // l = last element >= x (-1 if no such eleemnt) -- lowerbound
        // r = first element > x (n if no such element) -- upperbound
        return new int[]{l,r};
    }
 
    /**
        DATA STRUCTURES TEMPLATES
    */
    static abstract class Multiset<T> {
        protected final TreeMap<T, Integer> multiset;
		public Multiset() { multiset = new TreeMap<>(); }
        public void add(T x) { multiset.merge(x, 1, Integer::sum); }
        public void remove(T x) {
            multiset.merge(x, -1, Integer::sum); 
            if (multiset.get(x) <= 0) multiset.remove(x);
        }
        public T min() { return multiset.firstKey(); }
        public T max() { return multiset.lastKey(); }
        public int countLE(T x) { // count less than or equal
            return multiset.headMap(x, true).values()
                    .stream().mapToInt(Integer::intValue).sum();
        }
        public int count() { return multiset.values().stream().mapToInt(Integer::intValue).sum(); }
    }

    static abstract class DSU {
        protected final int[] parent;
        protected final int[] size;
        public DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        public int find(int v) {
            return parent[v] == v ? v : (parent[v] = find(parent[v]));
        }
        public boolean union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        public int size(int v) {
            return size[find(v)];
        }
        public boolean connected(int a, int b) {
            return find(a) == find(b);
        }
    }

    static abstract class SegmentTree { 
        protected final int[] st;
        protected final int[] lazy;
        protected final int[] a;
        public SegmentTree(int n, int[] a) {
            this.st = new int[4*n];
            this.lazy = new int[4*n];
            this.a = a;
        }
        protected abstract int combine(int left, int right);
        public void build(int v, int tl, int tr) {
            if (tl == tr) {
                st[v] = a[tl];
                return;
            }
            int tm = (tl + tr) >>> 1;
            build(v*2+1, tl, tm);
            build(v*2+2, tm+1, tr);
            st[v] = combine(st[v*2+1], st[v*2+2]);
        }
        protected abstract int update(int x, int u);
        protected abstract int updateLazy(int x, int u);
        protected abstract void push(int v); // lazy propagation
        public void update(int v, int tl, int tr, int pos, int u) {
            if (tl > tr) return;
            if (tl == tr) {
                st[v] = update(st[v], u);
                lazy[v] = updateLazy(lazy[v], u);
                return;
            }
            int tm = (tl + tr) >>> 1;
            if (pos <= tm) update(v*2+1, tl, tm, pos, u);
            else update(v*2+2, tm+1, tr, pos, u);
            st[v] = combine(st[v*2+1], st[v*2+2]);
        }
        protected abstract int identity();
        public int query(int v, int tl, int tr, int l, int r) {
            if (l > r) return identity();
            if (l <= tl && tr <= r) return st[v];
            push(v);
            int tm = (tl + tr) >>> 1;
            int left = query(v*2+1, tl, tm, l, Math.min(r, tm));
            int right = query(v*2+2, tm+1, tr, Math.max(l, tm+1), r);
            return combine(left, right);
        }
    }

    static abstract class FenwickTree {
        /**
        supporting
            1. point update
            2. range sum query (prefix sum)
        note: one-indexed (zero is skipped)
        ft[k] = query(k - p(k) + 1, k)
        p(k) = largest power of 2 that divides k
        use least significant one (lsone) to update/calc sum
            * defined in CP2 (Steven & Helix)
        query(a,b) = query(1,b) - query(1,a-1) for a > 1
        */
        int[] ft; // fenwick tree
        int[] a; // original array
        public FenwickTree(int n) {
            ft = new int[n+1];
            a = new int[n+1];
        }
        void set(int k, int u) {
            add(k, u - a[k]);
        }
        void add(int k, int u) {
            a[k] += u;
            for (; k <= ft.length; k += lsone(k)) ft[k] += u;
        }
        int query(int k) { // range sum query
            int res = 0;
            for (; k > 0; k -= lsone(k)) res += ft[k];
            return res;
        }
        int lsone(int x) { // least significant one
            return x & (-x);
        }
    }
 
    /**
        PRINTING 
    */
    static void print(FastScanner io, int[] a, String delimeter) { io.println(Arrays.stream(a).mapToObj(String::valueOf).collect(Collectors.joining(delimeter))); }
    static void print(FastScanner io, long[] a, String delimeter) { io.println(Arrays.stream(a).mapToObj(String::valueOf).collect(Collectors.joining(delimeter))); }
    static void print(FastScanner io, List<?> a, String delimeter) { io.println(a.stream().map(String::valueOf).collect(Collectors.joining(delimeter))); }

    /**
        IO
    */
    static class FastScanner extends PrintWriter {
        private BufferedReader br;
        private StringTokenizer st;
		// standard input
        public FastScanner() { this(System.in, System.out); }
		public FastScanner(InputStream i, OutputStream o) {
            super(o);
			st = new StringTokenizer("");
            br = new BufferedReader(new InputStreamReader(i));
        }
		// USACO-style file input
        public FastScanner(String problemName) throws IOException {
            super(problemName + ".out");
			st = new StringTokenizer("");
            br = new BufferedReader(new FileReader(problemName + ".in"));
        }
        // returns null if no more input
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());
                return st.nextToken();
            } catch (Exception e) { }
            return null;
        }
        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }
        public int nextInt() { return Integer.parseInt(next()); }  
        public double nextDouble() { return Double.parseDouble(next()); }   
        public long nextLong() { return Long.parseLong(next()); }   
        public int[] nextArray(int n) { int[] a = new int[n]; return nextArray(a); }
        public int[] nextArray(int[] a) { for (int i = 0; i < a.length; i++) a[i] = nextInt(); return a; }
        public long[] nextArray(long[] a) { for (int i = 0; i < a.length; i++) a[i] = nextLong(); return a; }
    }
}
