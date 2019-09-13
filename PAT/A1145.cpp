// //2018-8-10 9：44

// #include <iostream>
// #include <vector>

// using namespace std;

// bool isprime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n;i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     int tsize, n, m, a;
//     int i, j;
//     scanf("%d %d %d", &tsize, &n, &m);
//     while (!prime(tsize))//建立tsize长度的数组，tsize为大于输入值的最小素数
//         tsize++;
//     vector<int> v(tsize);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d",&a);
//         int flag = 0;
//         for (j = 0; j < tsize; j++)
//         {
//             int pos = (a + j * j) % tsize;//平方探测法插入数据
//             if (v[pos] == 0)
//             {
//                 v[pos] = a;
//                 flag = 1;
//                 break;
//             }
//         }
//         if (!flag)
//             printf("%d cannot be inserted.\n", a);
//     }

//     float ans = 0.0;
//     for (i = 0; i < m; i++)
//     {
//         scanf("%d", &a);
//         int cnt = 1;
//         for (j = 0; j < tsize; j++)
//         {
//             int pos = (a + j * j) % tsize;
//             if (v[pos] == a || v[pos] == 0)
//                 break;
//             cnt++;
//         }
//         ans += cnt;
//     }
//     printf("%.1f\n", ans / m);
//     return 0;
// }
//这都编译错误

//2018-8-10 19:19
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int msize,n,m;
	int i,j;
	int a;//输入值
	cin >> msize;
	cin >> n >> m;//输入个数
	while(!isPrime(msize))//如果输入的msize不是质数
		msize++;
	vector<int> v(msize);
	int cnt = 0;
	int flag = 0;
	for (i = 0;i < n; i++)
	{
		cin >> a;
		for (j = 0; j < msize; j++)
		{
			cnt = (a + j * j) % msize;
			if (v[cnt] == 0)
			{
				v[cnt] = a;
				flag = 1;//有位置标志位
				break;
			}
		}
		if (!flag)
			printf("%d cannot be inserted.\n",a);
		flag = 0;
	}
	//OK 19：50
	float ans = 0.0;
	int time = 1;
	for (i = 0; i < m; i++)
	{
		cin >> a;
		for (j = 0; j < msize; j++)
		{
			cnt = (a + j * j) % msize;
			if (v[cnt] == a || v[cnt] == 0)//找到了
			{
				break;
			}
			time += 1;
		}
		ans += time;
		//printf("%d ",time);
		time = 1;
	}
	//printf("\n");
	//printf("%f",ans);
	printf("%.1f",ans / m);
	return 0;
}
//怎么通过的连个正确答案都没有 是自己写的吗？