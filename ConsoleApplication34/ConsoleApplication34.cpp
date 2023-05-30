
#include<iostream> 

#include<conio.h> 

using namespace std;



int a, b, u, v, n, i, j, ne = 1;

int visited[10] = { 0 }, mincost = 0, cost[10][10];







int main()

{



    int path[100] = { 0 }; //В этот массив будут записываться вершины, по которым составиться путь 

    int path_index = 0;





    cout << "Enter the number of vertices  "; cin >> n;

    cout << "Enter the adjacency matrix\n";







    for (i = 1; i <= n; i++)

        for (j = 1; j <= n; j++)

        {

            cin >> cost[i][j];

            if (cost[i][j] == 0)

                cost[i][j] = 999; //999 - это что-типа бесконечности. Должно быть больше чем значения веса каждого из ребер в графе 

        }

    visited[1] = 1;

    cout << "\n";



    int min;

    while (ne < n)

    {

        for (i = 1, min = 999; i <= n; i++)

            for (j = 1; j <= n; j++)

                if (cost[i][j] < min)

                    if (visited[i] != 0)

                    {

                        min = cost[i][j];

                        a = u = i;

                        b = v = j;

                    }

        if (visited[u] == 0 || visited[v] == 0)

        {

            path[path_index] = b;

            path_index++;

            cout << "\n " << ne++ << "  " << a << "  " << b << min;

            mincost += min;

            visited[b] = 1;



        }

        cost[a][b] = cost[b][a] = 999;

    }





    cout << "\n";



    cout << 1 << " --> ";

    for (int i = 0; i < n - 1; i++)

    {

        cout << path[i];

        if (i < n - 2) cout << " --> ";

    }



    cout << "\n Minimal costs  (conventional units): " << mincost;

}

