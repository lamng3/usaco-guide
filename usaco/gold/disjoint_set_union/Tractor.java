package usaco.gold.disjoint_set_union;
/**
Problem url: https://usaco.org/index.php?page=viewproblem2&cpid=245

This problem is fairly interesting. One might not think of DSU right away :)
The intuition is that N^2 = 250000, each cell has at most 4 neighbors, making total number of edges
to be 1M edges. Each one having height difference D. 

The task here is to visit AT LEAST HALF of the cells (rounded up if odd).

We need to find a way to check if a tractor can reach at least half of the cells.
We now the minimum and maximum values of a grid, thus, we can deduce a maximum difference.
The intuition here is to use Binary Search On Value, with the value being the difference or the cost of a tractor.
Given we have a difference, the task now becomes finding connected components where each neighbor cell is no more than diff difference.
DSU jumps into place here, where it allows us to count the size of the components and effectively retrieve the maxsize among all components.
I do think DFS works, but it requires some household variable to maintain the size of the component.

Time Complexity: O(N^2 * ack(N^2)) 
where 1e6 be the maximum difference, ack(.) be the inverse ackermann function.
Note that the time complexity cost of binary search here can be treated as constant -- log(1e6)
Each cell has at most 4 neighbors, that is constant too :)
*/

import java.io.*;
import java.util.*;
import java.util.stream.*;
 
/**
    Nathan
*/
public class Tractor {
    static class DSU {
        int[] parent;
        int[] sz;
        public DSU(int n) {
            parent = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        int find(int v) {
            if (parent[v] == v) return v;
            return parent[v] = find(parent[v]);
        }
        boolean union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (sz[a] < sz[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
        int size(int v) { return sz[find(v)]; }
    }

    public static boolean inrange(int x, int y, int N) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }
    public static int hash(int i, int j) { return i * 1000 + j; }

    public static boolean check(int diff, int[][] grid, int N) {
        // count components where height difference <= diff
        // record maxsize
        int target = (N * N + 1) / 2;
        int MAXN = 1000 * 1000 + 5;
        DSU dsu = new DSU(MAXN);
        int[][] dirs = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
        int maxsize = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int[] d : dirs) {
                    int newi = i + d[0], newj = j + d[1];
                    if (!inrange(newi, newj, N)) continue;
                    if (Math.abs(grid[newi][newj] - grid[i][j]) > diff) continue;
                    dsu.union(hash(i, j), hash(newi, newj));
                    maxsize = Math.max(maxsize, dsu.size(hash(i,j)));
                }
            }
        }
        return maxsize >= target;
    }

    public static int search(int dmax, int[][] grid, int N) {
        int pos = dmax;
        for (int x = pos; x >= 1; x /= 2) {
            while (check(pos - x, grid, N)) {
                pos -= x;
            }
        }
        return pos;
    }

    public static void solve(FastScanner io) throws Exception {
        int N = io.nextInt();
        int min = oo, max = -1;

        int[][] grid = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = io.nextInt();
                min = Math.min(min, grid[i][j]);
                max = Math.max(max, grid[i][j]);
            }
        }

        int dmax = max - min;
        // difference running from [0, dmax]
        int answer = search(dmax, grid, N);
        io.println(answer);
    }

    /**
        MAIN
    */
    public static void main(String[] args) throws Exception {
        FastScanner io = new FastScanner("tractor"); // usaco
        // FastScanner io = new FastScanner();
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
    static void ruffle_sort(int[] a) { shuffle(a); sort(a); }
 
    // FACTORIALS & nCk
	static long[] factorials = new long[2_000_005];
	static long[] inverseFactorials = new long[2_000_005];
	static void precompute_factorials() {
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
    static int[] binary_search(int x, int[] a) {
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
    static class MultisetTemplate {
        TreeMap<Integer, Integer> ms;
		public MultisetTemplate() { ms = new TreeMap<>(); }
        void add(int x) { ms.put(x, ms.getOrDefault(x,0) + 1); }
        void remove(int x) {
            int c = ms.getOrDefault(x,0) - 1;
            if (c > 0) ms.put(x, c);
            else ms.remove(x);
        }
        int min() { return ms.firstKey(); }
        int max() { return ms.lastKey(); }
        int countLE(int x) {
            // headMap(x, true) gives keys <= x
            return ms.headMap(x, true)
                    .values()
                    .stream()
                    .mapToInt(Integer::intValue)
                    .sum();
        }
        int count() {
            return ms.values()
                    .stream()
                    .mapToInt(Integer::intValue)
                    .sum();
        }
        boolean contains(int x) { return ms.containsKey(x); }
        boolean isEmpty() { return ms.isEmpty(); }
    }

    static class DSUTemplate {
        int[] parent;
        int[] sz;
        public DSUTemplate(int n) {
            parent = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        public int find(int v) {
            if (parent[v] == v) return parent[v];
            return parent[v] = find(parent[v]);
        }
        public void union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (sz[a] < sz[b]) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                parent[b] = a;
                sz[a] += sz[b];
            }
        }
    }

    static class SegmentTreeTemplate { // example: max query
        static int[] st;
        static int[] lazy;
        static int[] a;
        public SegmentTreeTemplate(int N, int[] a) {
            this.st = new int[4*N];
            this.lazy = new int[4*N];
            this.a = a;
        }
        static void build(int v, int tl, int tr) {
            if (tl == tr) {
                st[v] = a[tl];
                return;
            }
            int tm = (tl + tr) / 2;
            build(v*2+1, tl, tm);
            build(v*2+2, tm+1, tr);
            st[v] = operator(st[v*2+1], st[v*2+2]);
        }
        static int operator(int left, int right) { 
            return Math.max(left, right); 
        }
        // lazy propagation
        static void push(int v) {
            // push down operation
            st[v*2+1] += lazy[v];
            st[v*2+2] += lazy[v];
            lazy[v*2+1] += lazy[v];
            lazy[v*2+2] += lazy[v];
            lazy[v] = 0;
        }
        static void update(int v, int tl, int tr, int pos, int addend) {
            if (tl > tr) return;
            if (tl == tr) {
                st[v] += addend;
                lazy[v] += addend;
                return;
            }
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2+1, tl, tm, pos, addend);
            else update(v*2+2, tm+1, tr, pos, addend);
            st[v] = operator(st[v*2+1], st[v*2+2]);
        }
        static int query(int v, int tl, int tr, int l, int r) { 
            if (l > r) return -oo;
            if (l <= tl && tr <= r) {
                return st[v];
            }
            push(v);
            int tm = (tl + tr) / 2;
            return operator(
                query(v*2+1, tl, tm, l, Math.min(r, tm)),
                query(v*2+2, tm+1, tr, Math.max(l, tm+1), r)
            );
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