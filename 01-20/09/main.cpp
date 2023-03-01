#include <iostream>

int main()
{
	int N, M, K;
	std::cin >> N >> M >> K;
	int** values = new int*[N];
	for (auto i = 0; i < N; i++)
	{
		values[i] = new int[M];
		for (auto j = 0; j < M; j++)
			std::cin >> values[i][j];
	}
	int** sums = new int*[N + 1];
	for (auto i = 0; i <= N; i++)
		sums[i] = new int[M + 1];
	for (auto i = 1; i <= N; i++)
		for (auto j = 1; j <= M; j++)
			sums[i][j] = values[i - 1][j - 1] + sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1];
	for (auto i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << sums[x2][y2] - sums[x2][y1 - 1] - sums[x1 - 1][y2] + sums[x1 - 1][y1 - 1] << std::endl;
	}
	for (auto i = 0; i < N; i++)
		delete[] values[i];
	delete[] values;
	for (auto i = 0; i <= N; i++)
		delete[] sums[i];
	delete[] sums;
	return 0;
}
