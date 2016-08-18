/*
 * map.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: Sindhu
 */
// constructing unordered_maps
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string,string> stringmap;

int main(){
	stringmap first({{"apple","red"},{"banana","yellow"}});
	cout<<"bucket count init.."<<first.bucket_count()<<endl;
	stringmap second(first);
	second.insert({{"guava","green"}});
	cout<< "second contains.."<<endl;
	for(auto& x: second) cout<<x.first<<":"<<x.second<<endl;
	cout<<"size.."<<second.size()<<endl;

	first.swap(second);
	cout<< "first contains.."<<endl;
	for(auto& x: first) cout<<x.first<<":"<<x.second<<endl;
	cout<< "second contains.."<<endl;
	for(auto& x: second) cout<<x.first<<":"<<x.second<<endl;

	cout<<"bucket count before.."<<first.bucket_count()<<endl;
	first.insert({{"mango","yellow"},{"cherry","red"}});
	cout<<"bucket count after.."<<first.bucket_count()<<endl;
	cout<<"bucket load factor.."<<first.load_factor()<<endl;
	cout<<"bucket max load factor.."<<first.max_load_factor()<<endl;
	cout<<"after rehashing.."<<endl;
	for(auto& x: first) cout<<x.first<<":"<<x.second<<endl;
	cout<<"max bucket count .."<<first.max_bucket_count()<<endl;
	cout<<"max size .."<<first.max_size()<<endl;

	stringmap third = {
			{"melon","blue"},
			{"plums","maroon"}
	};
	third.insert({"melon","squash"}); // duplicate key - won't get inserted
	cout<<"contents of third.."<<endl;
	stringmap::iterator it = third.begin();
	for(; it!=third.end();++it)
		cout<< it->first <<":"<< it->second<<endl;

	stringmap::iterator got = third.find("melon"); // find returns an iterator
	cout <<"find value of melon.." << got->second << endl;
	cout<<"plums is in the bucket.."<< third.bucket(third.find("plums")->first) <<endl;

	return 0;
}


