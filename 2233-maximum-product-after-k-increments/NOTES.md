k++;
pq.push(ele1);
pq.push(ele2);
}
int diff=ele2-ele1;
diff=min(k,diff);
ele1+=diff;
k-=diff;
pq.push(ele1);
pq.push(ele2);
}
else
{
int ele=pq.top();
pq.pop();
ele++;
pq.push(ele);
}
}
int ans=1;
while(!pq.empty())
{
ans=((ans%mod)*(pq.top()%mod))%mod;
pq.pop();
}
return (int)(ans%mod);
}
};
```