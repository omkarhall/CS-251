//
//  tests.cpp
//  CS 251 Project 5
//
//  Created by Veena Halleppanavar on 3/9/22.
//

#include <iostream>
#include "mymap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here..
    /*
    mymap<int, int> map;
    cout << "size: " << map.Size() << endl;
    int n = 10;
    int arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
    for (int i = 0; i < n; i++) {
        map.put(arr[i], arr[i]);
    }
    cout << "size: " << map.Size() << endl;
    cout << map.toString() << endl;
    cout << map.checkBalance() << endl;
    
    for (auto k : map) {
        cout << k << " ";
    }
    cout << endl;
    
    cout << "get for element not in map: " << map.get(0) << endl;
    //map[0];
    cout << map.toString() << endl;
    
    cout << "size: " << map.Size() << endl;
    bool b1 = map.contains(10);
    bool b2 = map.contains(15);
    cout << "contains 10: " << b1 << endl;
    cout << "contains 15: " << b2 << endl;
     */
    
    mymap<string, string> map2;
    cout << "size: " << map2.Size() << endl;
    string arr2[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for(int i = 0; i < 10; i++) {
        map2.put(arr2[i], arr2[i]);
    }
    cout << "size: " << map2.Size() << endl;
    cout << map2.toString() << endl;
    cout << map2["s"] << endl;
    /*
    mymap<int, int> map3;
    int arr3[] = {2, 1, 3};
    int order[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map3.put(arr3[i], arr3[i]);
    }
    int i = 0;
    for (auto key : map3) {
        cout << order[i++] << " " << key << " ";
    }
    
    mymap<int, int> mapCopy(map);
    cout << "mapCopy: " << endl;
    cout << "size: " << mapCopy.Size() << endl;
    cout << mapCopy.toString() << endl;
    
    mymap<int, int> mapCopy2;
    mapCopy2 = map3;
    mapCopy2 = map;
    cout << "mapCopy2: " << endl;
    cout << "size: " << mapCopy2.Size() << endl;
    cout << mapCopy2.toString() << endl;
     
    //map.put(15,17);
    
    vector<pair<int, int>> v = map.toVector();
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << " ";
        cout << endl;
    }
    cout << map.checkBalance() << endl;
    */
    
    mymap<int, int> map4;
    cout << "size: " << map4.Size() << endl;
    //int arr4[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
    int arr4[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    //int arr4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int arr4[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++) {
        map4.put(arr4[i], arr4[i]);
    }
    cout << "size: " << map4.Size() << endl;
    cout << map4.toString() << endl;
    for (auto k : map4) {
        cout << k << " ";
    }
    cout << endl;
    cout << map4.checkBalance() << endl;
    
    /*
    mymap<int, int> unbalanced;
    int arr5[] = {30, 15, 8, 6, 50};
    for (int i = 0; i < 5; i++) {
        unbalanced.put(arr5[i], arr5[i]);
    }
    cout << "size: " << unbalanced.Size() << endl;
    cout << unbalanced.toString() << endl;
    cout << unbalanced.checkBalance() << endl;
    */
    /*
    mymap<string, string> mapS;
    string arrS[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++) {
        mapS.put(arrS[i], arrS[i]);
    }
    cout << mapS.toString() << endl;
    cout << mapS.checkBalance() << endl;
     */
    mymap<char, char> mapC;
    char arrC[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    for (int i = 0; i < 10; i++) {
        mapC.put(arrC[i], arrC[i]);
    }
    cout << mapC.toString() << endl;
    cout << mapC.checkBalance() << endl;
    // test 1
    /*
    #include <gtest/gtest.h>
    #include <vector>
    #include <map>
    #include <sstream>
    #include "mymap.h"
     */
    /*
    TEST(mymap, putGetSizeContainsAndBracket) {
        // all unique values -- balanced
        mymap<double, double> map;
        double arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
        EXPECT_EQ(map.size(), 0);
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
            EXPECT_EQ(arr[i], map.get(arr[i]));
            EXPECT_EQ(true, map.contains(arr[i]));
            EXPECT_EQ(arr[i], map[arr[i]]);
        }
        EXPECT_EQ(map.Size(), 10);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map.get(0));
        EXPECT_EQ(0, map.get(12));
        EXPECT_EQ(false, map.contains(0));
        EXPECT_EQ(false, map.contains(12));
        EXPECT_EQ(0, map[0]);
     
        // duplicate values -- balanced
        mymap<int, char> map2;
        EXPECT_EQ(map2.size(), 0);
        int arr2[] = {30, 30, 15, 50, 8, 25, 70, 20, 28, 40, 40, 60};
        char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'h'};
        for (int i = 0; i < 12; i++) {
            map.put(arr2[i], ch[i]);
        }
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(ch[i], map2.get(arr[i]));
            EXPECT_EQ(true, map2.contains(arr[i]));
            EXPECT_EQ(ch[i], map2[arr[i]]);
        }
        EXPECT_EQ(map2.Size(), 10);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map2.get(0));
        EXPECT_EQ(0, map2.get(12));
        EXPECT_EQ(false, map2.contains(0));
        EXPECT_EQ(false, map2.contains(12));
        EXPECT_EQ(0, map2[0]);
     
        // unbalanced
        mymap<double, int> map3;
        EXPECT_EQ(map3.size(), 0);
        double arr3[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(i, map3.get(arr3[i]));
            EXPECT_EQ(true, map3.contains(arr3[i]));
            EXPECT_EQ(i, map3[arr3[i]]);
        }
        EXPECT_EQ(map3.size(), 10);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map3.get(0));
        EXPECT_EQ(0, map3.get(12));
        EXPECT_EQ(false, map3.contains(0));
        EXPECT_EQ(false, map3.contains(12));
        EXPECT_EQ(0, map3[0]);
     
        // very big mymap
        mymap<int, int> map4;
        EXPECT_EQ(map4.size(), 0);
        for (int i = 0; i < 1000; i++) {
            map4.put(i, i);
        }
        for (int i = 0; i < 1000; i++) {
            EXPECT_EQ(i, map4.get(i));
            EXPECT_EQ(true, map4.contains(i));
        }
        EXPECT_EQ(map4.size(), 1000);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map4.get(1001));
        EXPECT_EQ(0, map4.get(-1));
        EXPECT_EQ(false, map4.contains(1100));
        EXPECT_EQ(false, map4.contains(1200));
        EXPECT_EQ(0, map4[1001]);
     
        // mymap with random elements
        mymap<int, int> map5;
        map<int, int> correct;
        for (int i = 0; i < 10; i++) {
            int k = rand() % 10;
            int v = rand() % 10;
            map5.put(k, v);
            correct[k] = v;
            EXPECT_EQ(map5.get(k), correct[k]);
        }
        EXPECT_EQ(map5.Size(), correct.size());
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map5.get(15));
        EXPECT_EQ(0, map5.get(20));
        EXPECT_EQ(false, map5.contains(15));
        EXPECT_EQ(false, map5.contains(20));
        EXPECT_EQ(0, map5[15]);
     
        // mymap in increasing order
        mymap<int, int> map6;
        int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        EXPECT_EQ(map6.size(), 0);
        for (int i = 0; i < 10; i++) {
            map6.put(arr6[i], arr6[i]);
            EXPECT_EQ(arr6[i], map6.get(arr6[i]));
            EXPECT_EQ(true, map6.contains(arr6[i]));
        }
        EXPECT_EQ(map6.Size(), 10);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map6.get(0));
        EXPECT_EQ(0, map6.get(12));
        EXPECT_EQ(false, map6.contains(15));
        EXPECT_EQ(false, map6.contains(20));
        EXPECT_EQ(0, map6[15]);
        // string
        mymap<string, string> mapS;
        string arrS[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        for (int i = 0; i < 10; i++) {
            mapS.put(arrS[i], arrS[i]);
            EXPECT_EQ(arrS[i], mapS.get(arrS[i]));
            EXPECT_EQ(true, mapS.contains(arrS[i]));
        }
        EXPECT_EQ("", map6.get("w"));
        EXPECT_EQ("", map6.get("z"));
        EXPECT_EQ(false, map6.contains("z"));
        EXPECT_EQ(false, map6.contains("w"));
        EXPECT_EQ("", map6["z"]);

        // mymap in decreasing order
        mymap<int, int> map7;
        int arr7[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        EXPECT_EQ(map7.size(), 0);
        for (int i = 0; i < 10; i++) {
            map7.put(arr7[i], arr7[i]);
            EXPECT_EQ(arr7[i], map7.get(arr7[i]));
            EXPECT_EQ(true, map7.contains(arr7[i]));
        }
        EXPECT_EQ(map7.Size(), 10);
        // get, contains, [] on keys that do not exist
        EXPECT_EQ(0, map7.get(0));
        EXPECT_EQ(0, map7.get(12));
        EXPECT_EQ(false, map7.contains(15));
        EXPECT_EQ(false, map7.contains(20));
        EXPECT_EQ(0, map7[15]);
        // char
        mymap<char, char> map8;
        char arrC[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        for (int i = 0; i < 10; i++) {
            map8.put(arrC[i], arrC[i]);
            EXPECT_EQ(arrC[i], map8.get(arrC[i]));
            EXPECT_EQ(true, map8.contains(arrC[i]));
        }
        EXPECT_EQ('\0', map8.get('z'));
        EXPECT_EQ('\0', map8.get('w'));
        EXPECT_EQ(false, map8.contains('z'));
        EXPECT_EQ(false, map8.contains('w'));
        EXPECT_EQ('\0', map8['z']);
    }
     
     TEST(mymap, forEach) {
        // all unique values -- balanced
        mymap<double, double> map;
        stringstream ss();
        double arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
        }
        for (int key : map) {
            ss << “key: “ << key << “ value: “ << map[key] << endl;
        }
        ASSERT_EQ(map.toString(), ss.str());
        
        // duplicate values -- balanced
        mymap<int, char> map2;
        stringstream ss2();
        int arr2[] = {30, 30, 15, 50, 8, 25, 70, 20, 28, 40, 40, 60};
        char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'h'};
        for (int i = 0; i < 12; i++) {
            map2.put(arr2[i], ch[i]);
        }
        for (int key : map2) {
            ss2 << “key: “ << key << “ value: “ << map2[key] << endl;
        }
        ASSERT_EQ(map2.toString(), ss2.str());
     
        // unbalanced
        mymap<double, int> map3;
        stringstream ss3();
        double arr3[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        for (int key : map3) {
            ss2 << “key: “ << key << “ value: “ << map3[key] << endl;
        }
        ASSERT_EQ(map3.toString(), ss3.str());
     
        // very big mymap
        mymap<int, int> map4;
        stringstream ss4();
        for (int i = 0; i < 1000; i++) {
            map4.put(i, i);
        }
        for (int key : map4) {
            ss4 << “key: “ << key << “ value: “ << map4[key] << endl;
        }
        ASSERT_EQ(map4.toString(), ss4.str());
        
        // mymap with random elements
        mymap<int, int> map5;
        stringstream ss5();
        for (int i = 0; i < 10; i++) {
            int k = rand() % 10;
            int v = rand() % 10;
            map5.put(k, v);
        }
        for (int key : map5) {
            ss5 << “key: “ << key << “ value: “ << map5key] << endl;
        }
        ASSERT_EQ(map5.toString(), ss5.str());
     
        // mymap in increasing order
        mymap<int, int> map6;
        stringstream ss6();
        int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        for (int i = 0; i < 10; i++) {
            map6.put(arr6[i], arr6[i]);
        }
        for (int key : map6) {
            ss6 << “key: “ << key << “ value: “ << map6[key] << endl;
        }
        ASSERT_EQ(map6.toString(), ss6.str());
        // string
        mymap<string, string> mapS;
        stringstream sS();
        string arrS[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        for (int i = 0; i < 10; i++) {
            mapS.put(arrS[i], arrS[i]);
        }
        for (int key : mapS) {
            sS << “key: “ << key << “ value: “ << mapS[key] << endl;
        }
        ASSERT_EQ(mapS.toString(), sS.str());

        // mymap in decreasing order
        mymap<int, int> map7;
        int arr7[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        stringstream ss7();
        for (int i = 0; i < 10; i++) {
            map7.put(arr7[i], arr7[i]);
        }
        for (int key : map7) {
            ss7 << “key: “ << key << “ value: “ << map7[key] << endl;
        }
        ASSERT_EQ(map7.toString(), ss7.str());
        // char
        mymap<char, char> map8;
        stringstream ss8();
        char arrC[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        for (int i = 0; i < 10; i++) {
            map8.put(arrC[i], arrC[i]);
        }
        for (int key : map8) {
            ss8 << “key: “ << key << “ value: “ << map8[key] << endl;
        }
        ASSERT_EQ(map8.toString(), ss8.str());
        
     }
     
     TEST(mymap, equal) {
        // all unique values -- balanced
        mymap<double, double> map;
        mymap<double, double> mapCopy;
        double arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
        }
        mapCopy = map;
        EXPECT_EQ(map.Size(), mapCopy.Size();
        EXPECT_EQ(map.toString(), mapCopy.toString());
        EXPECT_EQ(map.toVector(), mapCopy.toVector());
        
        // duplicate values -- balanced
        mymap<int, char> map2;
        mymap<int, char> mapCopy2;
        char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'h'};
        int arr2[] = {30, 30, 15, 50, 8, 25, 70, 20, 28, 40, 40, 60};
        for (int i = 0; i < 12; i++) {
            map2.put(arr2[i], ch[i]);
        }
        mapCopy2 = map2;
        EXPECT_EQ(map2.Size(), mapCopy2.Size();
        EXPECT_EQ(map2.toString(), mapCopy2.toString());
        EXPECT_EQ(map2.toVector(), mapCopy2.toVector());
     
        // unbalanced
        mymap<double, int> map3;
        mymap<double, int> mapCopy3;
        double arr3[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        mapCopy3 = map3;
        EXPECT_EQ(map3.Size(), mapCopy3.Size();
        EXPECT_EQ(map3.toString(), mapCopy3.toString());
        EXPECT_EQ(map3.toVector(), mapCopy3.toVector());
     
        // very big mymap
        mymap<int, int> map4;
        mymap<int, int> mapCopy4;
        for (int i = 0; i < 1000; i++) {
            map4.put(i, i);
        }
        mapCopy4 = map4;
        EXPECT_EQ(map4.Size(), mapCopy4.Size();
        EXPECT_EQ(map4.toString(), mapCopy4.toString());
        EXPECT_EQ(map4.toVector(), mapCopy4.toVector());
     
        // mymap with random elements
        mymap<int, int> map5;
        mymap<int, int> mapCopy5;
        for (int i = 0; i < 10; i++) {
            int k = rand() % 10;
            int v = rand() % 10;
            map5.put(k, v);
        }
        mapCopy5 = map5;
        EXPECT_EQ(map5.Size(), mapCopy5.Size();
        EXPECT_EQ(map5.toString(), mapCopy5.toString());
        EXPECT_EQ(map5.toVector(), mapCopy5.toVector());
     
        // mymap in increasing order
        mymap<int, int> map6;
        mymap<int, int> mapCopy6;
        int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        for (int i = 0; i < 10; i++) {
            map6.put(arr6[i], arr6[i]);
        }
        mapCopy6 = map6;
        EXPECT_EQ(map6.Size(), mapCopy6.Size();
        EXPECT_EQ(map6.toString(), mapCopy6.toString());
        EXPECT_EQ(map6.toVector(), mapCopy6.toVector());
        // string
        mymap<string, string> mapS;
        mymap<string, string> mapCopyS;
        stringstream sS();
        string arrS[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        for (int i = 0; i < 10; i++) {
            mapS.put(arrS[i], arrS[i]);
        }
        mapCopyS = mapS;
        EXPECT_EQ(mapS.Size(), mapCopyS.Size();
        EXPECT_EQ(mapS.toString(), mapCopyS.toString());
        EXPECT_EQ(mapS.toVector(), mapCopyS.toVector());

        // mymap in decreasing order
        mymap<int, int> map7;
        mymap<int, int> mapCopy7;
        int arr7[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        for (int i = 0; i < 10; i++) {
            map7.put(arr7[i], arr7[i]);
        }
        mapCopy7 = map7;
        EXPECT_EQ(map7.Size(), mapCopy7.Size();
        EXPECT_EQ(map7.toString(), mapCopy7.toString());
        EXPECT_EQ(map7.toVector(), mapCopy7.toVector());
        // char
        mymap<char, char> map8;
        mymap<char, char> mapCopyC;
        char arrC[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        for (int i = 0; i < 10; i++) {
            map8.put(arrC[i], arrC[i]);
        }
        mapCopyC = map8;
        EXPECT_EQ(map8.Size(), mapCopyC.Size();
        EXPECT_EQ(map8.toString(), mapCopyC.toString());
        EXPECT_EQ(map8.toVector(), mapCopyC.toVector());
     }
     
     TEST(mymap, clearAndCopyConstructor) {
        // all unique values -- balanced
        mymap<double, double> map;
        double arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
        }
        map.clear();
        EXPECT_EQ(map.Size(), 0);
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
        }
        mymap<double, double> mapCopy(map);
        EXPECT_EQ(map.Size(), mapCopy.Size();
        EXPECT_EQ(map.toString(), mapCopy.toString());
        EXPECT_EQ(map.toVector(), mapCopy.toVector());
     
        // duplicate values -- balanced
        mymap<int, char> map2;
        char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'h'};
        int arr2[] = {30, 30, 15, 50, 8, 25, 70, 20, 28, 40, 40, 60};
        for (int i = 0; i < 12; i++) {
            map2.put(arr2[i], ch[i]);
        }
        map2.clear();
        EXPECT_EQ(map2.Size(), 0);
        for (int i = 0; i < 12; i++) {
            map2.put(arr2[i], ch[i]);
        }
        mymap<int, char> mapCopy2(map2);
        EXPECT_EQ(map2.Size(), mapCopy2.Size();
        EXPECT_EQ(map2.toString(), mapCopy2.toString());
        EXPECT_EQ(map2.toVector(), mapCopy2.toVector());
        
        // unbalanced
        mymap<double, int> map3;
        int double[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        map3.clear();
        EXPECT_EQ(map3.Size(), 0);
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        mymap<double, int> mapCopy3(map3);
        EXPECT_EQ(map3.Size(), mapCopy3.Size();
        EXPECT_EQ(map3.toString(), mapCopy3.toString());
        EXPECT_EQ(map3.toVector(), mapCopy3.toVector());
     
        // very big mymap
        mymap<int, int> map4;
        for (int i = 0; i < 1000; i++) {
            map4.put(i, i);
        }
        map4.clear();
        EXPECT_EQ(map4.Size(), 0);
        for (int i = 0; i < 1000; i++) {
            map4.put(i, i);
        }
        mymap<int, int> mapCopy4(map4);
        EXPECT_EQ(map4.Size(), mapCopy4.Size();
        EXPECT_EQ(map4.toString(), mapCopy4.toString());
        EXPECT_EQ(map4.toVector(), mapCopy4.toVector());
     
        // mymap with random elements
        mymap<int, int> map5;
        for (int i = 0; i < 10; i++) {
            int k = rand() % 10;
            int v = rand() % 10;
            map5.put(k, v);
        }
        map5.clear();
        EXPECT_EQ(map5.Size(), 0);
        for (int i = 0; i < 10; i++) {
            int k = rand() % 10;
            int v = rand() % 10;
            map5.put(k, v);
        }
        mymap<int, int> mapCopy5(map5);
        EXPECT_EQ(map5.Size(), mapCopy5.Size();
        EXPECT_EQ(map5.toString(), mapCopy5.toString());
        EXPECT_EQ(map5.toVector(), mapCopy5.toVector());
     
        // mymap in increasing order
        mymap<int, int> map6;
        int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        for (int i = 0; i < 10; i++) {
            map6.put(arr6[i], arr6[i]);
        }
        map6.clear();
        EXPECT_EQ(map6.Size(), 0);
        for (int i = 0; i < 10; i++) {
            map6.put(arr6[i], arr6[i]);
        }
        mymap<int, int> mapCopy6(map6);
        EXPECT_EQ(map6.Size(), mapCopy6.Size();
        EXPECT_EQ(map6.toString(), mapCopy6.toString());
        EXPECT_EQ(map6.toVector(), mapCopy6.toVector());
        // string
        mymap<string, string> mapS;
        string arrS[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        for (int i = 0; i < 10; i++) {
            mapS.put(arrS[i], arrS[i]);
        }
        mapS.clear();
        EXPECT_EQ(mapS.Size(), 0);
        for (int i = 0; i < 10; i++) {
            mapS.put(arrS[i], arrS[i]);
        }
        mymap<string, string> mapCopyS(mapS);
        EXPECT_EQ(mapS.Size(), mapCopyS.Size();
        EXPECT_EQ(mapS.toString(), mapCopyS.toString());
        EXPECT_EQ(mapS.toVector(), mapCopyS.toVector());

        // mymap in decreasing order
        mymap<int, int> map7;
        int arr7[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        for (int i = 0; i < 10; i++) {
            map7.put(arr7[i], arr7[i]);
        }
        map7.clear();
        EXPECT_EQ(map7.Size(), 0);
        for (int i = 0; i < 10; i++) {
            map7.put(arr7[i], arr7[i]);
        }
        mymap<int, int> mapCopy7(map7);
        EXPECT_EQ(map7.Size(), mapCopy7.Size();
        EXPECT_EQ(map7.toString(), mapCopy7.toString());
        EXPECT_EQ(map7.toVector(), mapCopy7.toVector());
        // char
        mymap<char, char> map8;
        char arrC[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        for (int i = 0; i < 10; i++) {
            map8.put(arrC[i], arrC[i]);
        }
        map8.clear();
        EXPECT_EQ(map8.Size(), 0);
        for (int i = 0; i < 10; i++) {
            map8.put(arrC[i], arrC[i]);
        }
        mymap<char, char> mapCopyC(map8);
        EXPECT_EQ(map8.Size(), mapCopyC.Size();
        EXPECT_EQ(map8.toString(), mapCopyC.toString());
        EXPECT_EQ(map8.toVector(), mapCopyC.toVector());
     }
     
     TEST(mymap, checkBalance) {
        // string, lean right
        mymap<string, string> map;
        string arr[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
        for (int i = 0; i < 10; i++) {
            map.put(arr[i], arr[i]);
        }
        string correct = "key: e, nL: 4, nR: 5\nkey: b, nL: 1, nR: 2\n";
        correct += "key: a, nL: 0, nR: 0\nkey: c, nL: 0, nR: 1\n";
        correct += "key: d, nL: 0, nR: 0\nkey: g, nL: 1, nR: 3\n";
        correct += "key: f, nL: 0, nR: 0\nkey: i, nL: 1, nR: 1\n";
        correct += "key: h, nL: 0, nR: 0\nkey: j, nL: 0, nR: 0\n";
        EXPECT_EQ(correct, map.checkBalance());
     
        // char, lean left
        mymap<char, char> map2;
        char arr2[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        for (int i = 0; i < 10; i++) {
            map2.put(arr2[i], arr2[i]);
        }
        string correct2 = "key: g, nL: 6, nR: 3\nkey: c, nL: 2, nR: 3\n";
        correct2 += "key: a, nL: 0, nR: 1\nkey: b, nL: 0, nR: 0\n";
        correct2 += "key: e, nL: 1, nR: 1\nkey: d, nL: 0, nR: 0\n";
        correct2 += "key: f, nL: 0, nR: 0\nkey: i, nL: 1, nR: 1\n";
        correct2 += "key: h, nL: 0, nR: 0\nkey: j, nL: 0, nR: 0\n";
        EXPECT_EQ(correct2, map2.checkBalance());
     
        // <double, int>, zigzag
        mymap<double, int> map3;
        double arr3[] = {50, 29, 60, 39, 20, 55, 71, 69, 83, 99};
        for (int i = 0; i < 10; i++) {
            map3.put(arr3[i], i);
        }
        string correct3 = "key: 50, nL: 3, nR: 6\nkey: 29, nL: 1, nR: 1\n";
        correct3 += "key: 20, nL: 0, nR: 0\nkey: 39, nL: 0, nR: 0\n";
        correct3 += "key: 69, nL: 2, nR: 3\nkey: 55, nL: 0, nR: 1\n";
        correct3 += "key: 60, nL: 0, nR: 0\nkey: 83, nL: 1, nR: 1\n";
        correct3 += "key: 71, nL: 0, nR: 0\nkey: 99, nL: 0, nR: 0\n";
     
        // int zigzag
        mymap<int, int> map4;
        int arr4[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
        for (int i = 0; i < 10; i++) {
            map4.put(arr4[i], i);
        }
        string correct4 = "key: 5, nL: 4, nR: 5\nkey: 2, nL: 1, nR: 2\n";
        correct4 += "key: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 1\n";
        correct4 += "key: 4, nL: 0, nR: 0\nkey: 8, nL: 2, nR: 2\n";
        correct4 += "key: 7, nL: 1, nR: 0\nkey: 6, nL: 0, nR: 0\n";
        correct4 += "key: 9, nL: 0, nR: 1\nkey: 10, nL: 0, nR: 0\n";
     }
     */
    return 0;
}
