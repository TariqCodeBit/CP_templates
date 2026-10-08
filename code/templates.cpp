#include <iostream>
#include <vector>
using namespace std;
//===== [ordered_set]  ===

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

//==== [Sieve for prime factorization] ==== 
const int N=1e7;
vector<int>seiev_prime_fac(){
    vector<int>divide(N+1,0);
    vector<bool>Is_prime(N+1,true);
    Is_prime[0]=Is_prime[1]=false;
    for(int i=2;i <= N;i++){
      if(Is_prime[i]){
        divide[i]=i;
        for(int j=i*i;j <= N;j+=i){
            Is_prime[j]=false;
            if(divide[j]==0){
                divide[j]=i;
            }
        }
      }
    }
    return divide;
}

vector<int>prime_factorization(int n ,vector<int>& div){
    vector<int>ret;
    while (n !=1)
    {
        int p=div[n];
        ret.push_back(p);
         n/=p;
    }
    return ret;
    
}


//=======[Sieve N log(log(N))]====
vector<bool> sieve(int n){
    vector<bool>Is_prime(n+1,true);
    Is_prime[0]=Is_prime[1]=false;
    for(int i=2;i <= n;i++){
        if(Is_prime[i]){
            for(int j=2*i;j <= n;j+=i){
                Is_prime[j]=false;
            }
        }
    }
    return Is_prime;
}
//======================================
struct BinaryTrie{
	struct Node{
		Node*ch[2];
		int freq[2];
		Node(){
			ch[0]=ch[1]=0;
			freq[0]=freq[1]=0;
		}
	};
	BinaryTrie(){
		insert(0);
	}
	Node*root=new Node();
	void insert(int x){
		Node*cur=root;
		for(int i=29;i >=0;i--){
          int idx=(x>>i)&1;// 0 1
		  if(cur->ch[idx]==0){
			cur->ch[idx]=new Node();
		  }
		  cur->freq[idx]++;
		  cur=cur->ch[idx];

		}
	}
	void del(int n,int i,Node*cur){
		if(i==-1)
		   return;
	   bool idx=(n>>i)&1;
	   del(n,i-1,cur->ch[idx]);
		cur->freq[idx]--;

		if(cur->freq[idx]==0){
			delete cur->ch[idx];
			cur->ch[idx]=0;
		}
	}
    int mxXor(int n){
	  Node*cur=root;
	  int ans=0;
	  for(int i=29;i >=0;i--){
		bool idx=(n>>i)&1;
		if(cur->ch[idx^1]==0){
			cur=cur->ch[idx];
		}else{
			cur=cur->ch[idx^1];
		  ans|=1<<i;
		}
		  
	  }

	  return ans; 
	}

};
//=================================