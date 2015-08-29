//// Lab 009 
//// Name : Kim Bo Woon
//// Student ID : 20113259
//
//void Graph::Edge(int v1, int v2, int cost)
//{
//	//	cerr << "NEED TO IMPLEMENT" << endl;
//	Cost[v1][v2] = cost;
//}
//
//void Graph::Floyd()
//{
//	for (int i = 0; i < numofnodes; i++)
//	{
//		for (int j = 0; j < numofnodes; j++)
//			kay[i][j] = -1;
//	}
//	for (int i = 0; i < numofnodes; i++)
//	{
//		for (int j = 0; j < numofnodes; j++)
//			c[i][j] = Cost[i][j];
//	}
//	for (int k = 0; k < numofnodes; k++)
//	{
//		for (int i = 0; i < numofnodes; i++)
//		{
//			for (int j = 0; j < numofnodes; j++)
//			{
//				if (c[i][j] > c[i][k] + c[k][j])
//				{
//					kay[i][j] = k;
//					c[i][j] = c[i][k] + c[k][j];
//				}
//			}
//		}
//	}
//}
//
//void Graph::outputPath(int i, int j)
//{ // does not output first vertex (i) on path
//	/*cout << endl << "Cost" << endl;
//	for (int i = 0; i < numofnodes; i++)
//	{
//	for (int j = 0; j < numofnodes; j++)
//	cout << Cost[i][j] << "	";
//	cout << endl;
//	}
//	cout << "kay" << endl;
//	for (int i = 0; i < numofnodes; i++)
//	{
//	for (int j = 0; j < numofnodes; j++)
//	cout << kay[i][j] << "	";
//	cout << endl;
//	}
//	cout << "C" << endl;
//	for (int i = 0; i < numofnodes; i++)
//	{
//	for (int j = 0; j < numofnodes; j++)
//	cout << c[i][j] << "	";
//	cout << endl;
//	}*/
//	if (i == j)
//		return;
//	if (kay[i][j] == -1)  // no intermediate vertices on path
//		cout << "-" << j;
//	else { // kay[i][j] is an intermediate vertex on the path
//		outputPath(i, kay[i][j]);
//		outputPath(kay[i][j], j);
//	}
//}