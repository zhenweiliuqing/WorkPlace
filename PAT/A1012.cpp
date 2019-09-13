#include <iostream>
#include <algorithm>
using namespace std;
struct node 
{
    int id, best;
    int score[4], rank[4];
} stu[2005];
int exist[1000000], flag = -1;
bool cmp1(node a, node b)
{
    return a.score[flag] > b.score[flag];
}
int main()
{
    int n, m, id;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
    }

    for (flag = 0; flag <= 3; flag++)
    {
        sort(stu, stu + n, cmp1);//这也能排序？？？
        stu[0].rank[flag] = 1;//???
        for (int i = 1; i < n; i++)
        {
            stu[i].rank[flag] = i + 1;
            if (stu[i].score[flag] == stu[i-1].score[flag])//如果分等于上一个同学
                stu[i].rank[flag] = stu[i - 1].rank[flag];//那么排名也相同
        }
    }

    for (int i = 0; i < n; i++)
    {
        exsit[stu[i].id] = i + 1;//跟排名无关 只是存在的标记
        stu[i].best = 0;
        int min = stu[i].rank[0];
        for (int j = 1; j <= 3; j++)
        {
            if (stu[i].rank[j] < min)
            {
                min = stu[i].rank;
                stu[i].best = j;
            }
        }
    }

    char c[5] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++)
    {
        cin >> id;
        int temp = exist[id];
        if (temp)
        {
            int best = stu[temp - 1].best;//是0-3中的哪个呢？
            cout << stu[temp - 1].rank[best] << c[best];
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
    return 0;
}


/*
//2018-8-22 20：27

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct 
{
    int ID;
	int A;
	int C;
	int M;
	int E;
    int best_rank;
} Rank;
int main()
{
    int n, m;
    cin >> n >> m;//输入学生个数和要查询的学生数
    vector<Rank> stu(n);
	vector<int> A(n);
	vector<int> C(n);
	vector<int> M(n);
	vector<int> E(n);

 	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].ID >> stu[i].C >> stu[i].M >> stu[i].E;
		stu[i].A = (stu[i].C + stu[i].M  + stu[i].E) / 3; 
		A[i] = stu[i].A;
		C[i] = stu[i].C;
		M[i] = stu[i].M;
		E[i] = stu[i].E;
	}

	for (int i = 0; i < n; i++)
	{
		sort(&A[0], &A[0] + n);
		sort(&C[0], &C[0] + n);
		sort(&M[0], &M[0] + n);
		sort(&E[0], &E[0] + n);
	}
	int ID;
	for (int i = 0; i < m; i++)
	{
		cin >> ID;
		for (int j = 0; j < n; j++)
		{
			if (ID == stu[j].ID)
			{
				//开始寻找最好成绩
				for (int k = 0; k < 4; k++)
				{
					for (int v = 0; v < n; v++)
						if (stu[j].A == A[v])//找到平均成绩
						{
							if (v)
						}
				}
			}
		}
	}
    return 0;
}
//21:24 太复杂了 方法估计不对
*/

//2018-8-23 16:53
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int ID;
	int score[4];//A C M E
	int best;
	int locate;
	int rank[4];
};
int index = 0;
bool rule(node a, node b)
{
	return a.score[index] > b.score[index];
}
int main()
{
	int n,m;
	cin >> n >> m;
	node *stu = new node[n];
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].ID >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
	}

	//开始排序算法
	for (index = 0; index < 4; index++)
	{
		sort(stu, stu + n, rule);//依次按照 A C M E进行排序
		for (int i = 0; i < n; i++)
		{
			stu[i].rank[index] = i + 1;
			if (stu[i].score[index] == stu[i - 1].score[index])//跟前面人并列
				stu[i].rank[index] = stu[i - 1].rank[index];
		}
	}
	//名次排好之后 得出最好名次
	char c[4] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < n; i++)
	{
		stu[i].best = stu[i].rank[0];//默认把平均分作为最好成绩
		stu[i].locate = 0;
		for (int j = 1; j < 4 ;j++)
		{
			if (stu[i].rank[j] < stu[i].best)
			{
				stu[i].best = stu[i].rank[j];
				stu[i].locate = j;
			}
		}
	}
	int id;
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		for (int j = 0; j < n; j++)
		{
			if (id == stu[j].ID)
			{
				cout << stu[j].best << " " << c[stu[j].locate] <<endl;
                //cout << stu[j].rank[stu[j].locate] << " " << c[stu[j].locate] <<endl;//同样正确！！！
                break;
			}
			if (j == n - 1)
				cout << "N/A" << endl;
		}
	}
	delete[] stu;
	return 0;
}
//17:50 答案正确！！！