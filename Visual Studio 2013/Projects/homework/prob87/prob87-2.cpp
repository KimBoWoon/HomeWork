//#include "prob87-2.h"
#include "prob87-3.h"

const int max_size=100;

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream>>cases;

	Vector2<int> vec2[max_size], v2sum(0, 0);
	Vector3<int> vec3[max_size], v3sum(0, 0, 0);
	int dotproduct;

	for(int i=0;i<cases;i++)
	{
		int px, py;

		inStream>>px>>py;
		Vector2<int> v2(px, py);
		vec2[i]=v2*(i+1);
		if(i%2)
			v2sum+=v2;
		else
			v2sum-=v2;
	}
	dotproduct=v2sum.dot(vec2[0]);

	cout<<v2sum<<" "<<vec2[cases-1].squaredlength()<<" "<<dotproduct<<" "<<vec2[0].perp()<<endl;

	for(int i=0;i<cases;i++)
	{
		int px, py, pz;

		inStream>>px>>py>>pz;
		Vector3<int> v3(px, py, pz);
		vec3[i]=v3*(i+1);
		if(i%2)
			v3sum+=v3;
		else
			v3sum-=v3;
	}
	dotproduct=v3sum.dot(vec3[0]);

	cout<<v3sum<<" "<<vec3[cases-1].squaredlength()<<" "<<dotproduct<<" "<<vec3[0].cross(v3sum)<<endl;
	
	inStream.close();
}