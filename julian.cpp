// Julian Date <=> Gregorian Calendar Converter
// By: rui_er (luogu,codeforces,atcoder...)
#include "julian-header/color.cpp"
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const ll month[2][13] = {{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
					     {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

ll n;
struct Date {
	ll d, m, y;
	Date(ll a=0, ll b=0, ll c=0) : d(a), m(b), y(c) {}
	Date(tm qwq) : d(qwq.tm_mday), m(1+qwq.tm_mon), y(1900+qwq.tm_year) {}
	~Date() {}
	bool check() {
		if(y < 0) return (-y) % 4 == 1;
		if(y <= 1582) return y % 4 == 0;
		return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	}
	Date& operator ++ () {
		if(d == 4 && m == 10 && y == 1582) return *this = Date(15, 10, 1582);
		++d;
		if(d > month[check()][m]) {d = 1; ++m;}
		if(m > 12) {m = 1; ++y; if(!y) ++y;}
		return *this;
	}
	Date operator ++ (int) {
		Date res = *this;
		++*this;
		return res;
	}
	bool cmp(const Date &a) {
		if(y != a.y) return y < a.y;
		if(m != a.m) return m < a.m;
		return d < a.d;
	}
	void print() {
		printf("%lld %lld %lld", d, m, abs(y));
		if(y < 0) printf(" BC");
		puts("");
	}
}dt(1, 1, -4713), ans[10000005];

int main(int argc, char **argv) {
	rep(i, 0, 10000000) ans[i] = dt++;
	if(argc > 1) {
		rep(_, 1, argc-1) {
			char op[114514];
			strcpy(op, argv[_]);
			if(op[0] == 'n' && op[1] == 'o' && op[2] == 'w' && op[3] == '\0') {
				ll l = 0, r = 10000000;
				double _ = 0;
				time_t cur = time(0);
				tm *qwq = localtime(&cur);
				Date today = Date(*qwq);
				printf("Gregorian Calendar %04d-%02d-%02d %02d:%02d:%02d\n"
						, 1900+qwq->tm_year, 1+qwq->tm_mon, qwq->tm_mday
						, qwq->tm_hour, qwq->tm_min, qwq->tm_sec);
				while(l <= r) {
					ll mid = (l + r) >> 1;
					if(ans[mid].cmp(today)) l = mid + 1;
					else r = mid - 1, _ = mid;
				}
				_ += 1.0 * (qwq->tm_hour * 3600 + qwq->tm_min * 60 + qwq->tm_sec - 43200) / 86400;
				printf("Julian Date %.8lf\n", _);
			}
		}
		return 0;
	}
	printf("Please input a julian date: ");
	try {
		scanf("%lld", &n);
		if(n < 0 || n > 10000000) throw "Invalid julian date (must be in [0, 10000000])";
		ans[n].print();
	}
	catch(const char* err_msg) {prt_err(err_msg);}
	return 0;
}
