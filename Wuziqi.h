#ifndef WUZIQI_H
#define WUZIQI_H
/*��������Ϸ����Ϸģ���ʵ��
  zwdnet
  2010��3��
  zwdnet@163.com
  2011��9���޸ģ���ֲ��Linux�µ�Qt������
*/
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

class POINT
{
public:
	int x;
	int y;
	POINT(const int X=-1, const int Y=-1)
	    {x = X; y = Y;};
};

//��������Ϸ�࣬������Ϸ��صĲ���
class Wuziqi
{
private:
    int N; //���̴�С
    vector<vector<int> > Data; //������ÿ�����ӵ�״̬,0ΪɶҲû�У�1Ϊ���壬2Ϊ����
    POINT ps_Now; //��¼�������һ����λ��,�����ر��ʾ
    int Total; //���������������ж��Ƿ��Ѿ�������������Ϊ����

public: //�������õĽӿ�
    Wuziqi(const int n = 15); //���캯����Ĭ�ϴ�СΪ20
    ~Wuziqi(void);
    void Init(void); //���ݳ�ʼ��
    void GetData(vector<vector<int> > & data); //��ȡ��Ϸ���ݣ����ڻ�ͼ
    void Judge(int & Who); //�жϵ�ǰ�����Ƿ������Ӯ��Who = 1�ڷ�(��)ʤ��Who = 2�׷�
                            //ʤ��Who = 0��û�н���
    bool Fall(const POINT & ps, const int & who,
	     const int & beginPos, const int & endPos); 
          //������,�������������Ч����false;
    bool UnFall(const POINT & ps, const int & who,
	     const int & beginPos, const int & endPos);
         //ȡ�����ӣ������㷨4
    void Clear(void); //�����Ϸ����
    void Run(POINT & ps, const int & Which, const int & Who); //���������
		 
private://���ߺ���
    bool ChangePos(const POINT & srcPos, POINT & desPos,
	     const int & beginPos, const int & endPos);  //���������ת��

private://�����㷨ģ��
    //�㷨1
    void Way1(POINT & ps); //����1���ֿ�д�������µ��㷨ʱ�Ͳ��ظĶ���֮��ĵ��õĳ���
    //�㷨2
    void Way2(POINT & ps);
    void SetScore(const int i, const int j, const int Who,
                  vector<vector<int> > & State); //���ֺ���
    int p_Score(int num, int bp[]); //ʵ�ʵ����ֺ���
    bool first; //�Ƿ��ǵ�һ��
    //�㷨3������㷨
    void Way3(POINT & ps);
    /*
    //�㷨4: �������㷨
    void Way4(POINT & ps);
    int maxDepth;  //���������ȣ�Ĭ��Ϊ1
    int depth;
    void setDepth(const int & dep); //��������������
    void Search(const int & i, const int & j);  //��������
    //vector<vector<int> > & bestStep; //��¼�����������
    */
};
#endif
