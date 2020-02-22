//
// Created by 0864h on 2020-02-22.
//
#include<iostream>
#include<queue>
using namespace std;
int b[101][101],sec[101],n,k=0,count=0,j=-1,r=0,l=0;
bool sim[101][101];
char lr[101];
queue<pair<int,int>> q;
int rotate(int x, int y)
{
    int i,rot;
    k++;j++;
    if(lr[j]=='D')
        r++;
    if(lr[j]=='L')
        l++;
    rot = r%4-l%4;
    if(rot<0)
        rot += 4;
    if(rot==1)
    {
        for(i=x+1;i<=n;i++)
        {
            if(sim[i][y]==true)
                return count;
            if(b[i][y] == 1)
            {
                b[i][y]=0;
                q.push(make_pair(i,y));
                sim[i][y]=true;
            }
            else
            {
                sim[q.front().first][q.front().second] = false;
                q.pop();
                q.push(make_pair(i,y));
                sim[i][y]=true;
            }
            count++;
            if(count==sec[k])
            {
                rotate(i,y);
                break;
            }
        }
        return count+1;
    }
    if(rot==2)
    {
        for(i=y-1;i>=1;i--)
        {
            if(sim[x][i]==true)
                return count;
            if(b[x][i] == 1)
            {
                b[x][i]=0;
                q.push(make_pair(x,i));
                sim[x][i]=true;
            }
            else
            {
                sim[q.front().first][q.front().second] = false;
                q.pop();
                q.push(make_pair(x,i));
                sim[x][i]=true;
            }
            count++;
            if(count==sec[k])
            {
                rotate(x,i);
                break;
            }
        }
        return count+1;
    }
    if(rot==3)
    {
        for(i=x-1;i>=1;i--)
        {
            if(sim[i][y]==true)
                return count;
            if(b[i][y] == 1)
            {
                b[i][y]=0;
                q.push(make_pair(i,y));
                sim[i][y]=true;
            }
            else
            {
                sim[q.front().first][q.front().second] = false;
                q.pop();
                q.push(make_pair(i,y));
                sim[i][y] = true;
            }
            count++;
            if(count==sec[k])
            {
                rotate(i,y);
                break;
            }
        }
        return count+1;
    }
    if(rot==0)
    {
        for(i=y+1;i<=n;i++)
        {
            if(sim[x][i]==true)
                return count;
            if(b[x][i] == 1)
            {
                b[x][i]=0;
                q.push(make_pair(x,i));
                sim[x][i] = true;
            }
            else
            {
                sim[q.front().first][q.front().second] = false;
                q.pop();
                q.push(make_pair(x,i));
                sim[x][i] = true;
            }
            count++;
            if(count==sec[k])
            {
                rotate(x,i);
                break;
            }
        }
        return count+1;
    }
}
int main()
{
    int i,apple,row,column,l;
    cin>>n>>apple;//보드의 크기와 사과의 갯수
    for(i=0;i<apple;i++)
    {
        cin>>row>>column;//사과의 위치
        b[row][column] = 1;
    }
    cin>>l;//방향 변환 횟수
    for(i=1;i<=l;i++)
        cin>>sec[i]>>lr[i];
    sim[1][1] = true;
    q.push(make_pair(1,1));
    cout<<rotate(1,1);
}
