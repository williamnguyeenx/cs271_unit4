//
//  test_bst_example.cpp
//  CS 271 BST Project: Example Test File
//
//  Created by Dr. Stacey Truex
//

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "usecase.cpp"
#include "bst.cpp"

using namespace std;

void test_empty() {
    // int
    try
    {
        BST<string, int> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one",1);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // float
    try
    {
        BST<string, float> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one",1.5);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // string
    try
    {
        BST<string, string> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one","two");
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    //char
    try
    {
        BST<string, char> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one",'a');
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // bool
    try
    {
        BST<string, bool> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one",true);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // data string 
    try
    {
        BST<int, string> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(1,"one");
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // data float 
    try
    {
        BST<int, float> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(1,5.5);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    // data bool 
    try
    {
        BST<int, bool> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(1,true);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert() {
    // int
    try {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for(int i = 2; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }

    // float
    try {
        BST<string, float> bst;
        bst.insert("one", 1.5);
        string bst_str = bst.to_string();
        if(bst_str != "1.5") {
            cout << "Incorrect result of inserting (\"one\", 1.5). Expected 1.5 but got" << endl;
        }
        for(int i = 2; i <= 10; i++) {
            bst.insert("some data", i+0.5);
        }
        bst_str = bst.to_string();
        if(bst_str != "1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5") {
            cout << "Incorrect result of inserting keys 1.5-10.5 in order. Expected 1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]+0.5);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5.5 2.5 7.5 1.5 3.5 6.5 9.5 4.5 8.5 10.5") {
            cout << "Incorrect result of inserting keys {5.5 2.5 7.5 1.5 3.5 6.5 9.5 4.5 8.5 10.5}. Expected 5.5 2.5 7.5 1.5 3.5 6.5 9.5 4.5 8.5 10.5 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }

    // string
    try {
        BST<string, string> bst;
        bst.insert("one", "aa");
        string bst_str = bst.to_string();
        if(bst_str != "aa") {
            cout << "Incorrect result of inserting (\"one\", aa). Expected aa but got : " << bst_str << endl;
        }
        string series[5] = {"ee", "bb", "ff", "aa", "cc"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 5; i++) {
            balanced_bst.insert("some data", series[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "ee bb ff aa cc") {
            cout << "Incorrect result of inserting keys {ee, bb, ff, aa, cc}. Expected ee, bb, ff, aa, cc but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }

    // bool
    try {
        BST<bool, int> bst;
        bst.insert(true, 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for(int i = 2; i <= 10; i++) {
            bst.insert(false, i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<bool, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(false, vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }

}

void test_get() {
    //string
    try {
        BST<string, int> bst;
        string val = bst.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("one",1);
        val = bst.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }

    //int
    try {
        BST<int, int> bst;
        int val = bst.get(0);
        if(val!=0) {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert(1,1);
        val = bst.get(1);
        if(val != 1) {
            cout << "Incorrect get result. Expected \"1\" but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }

    //float
    try {
        BST<float, int> bst;
        float val = bst.get(0);
        if(val!=0) {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert(5.5,1);
        val = bst.get(1);
        if(val != 5.5) {
            cout << "Incorrect get result. Expected \"5.5\" but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }

    //bool
    try {
        BST<bool, int> bst;
        bool val = bst.get(0);
        if(val!=0) {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert(true,1);
        val = bst.get(1);
        if(val != true) {
            cout << "Incorrect get result. Expected \"true\" but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove() {
    //int
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }

    //float
    try {
        float vals[10] = {5.5, 2.5, 7.5, 1.5, 3.5, 4.5, 6.5, 9.5, 8.5, 10.5};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7.5);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5.5 2.5 8.5 1.5 3.5 6.5 9.5 4.5 10.5") {
            cout << "Incorrect result of removing 7.5. Expected 5.5 2.5 8.5 1.5 3.5 6.5 9.5 4.5 10.5 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }

    //string
    try {
        string vals[6] = {"f", "b", "h", "a", "c", "p"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 6; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove("a");
        string bst_str = balanced_bst.to_string();
        if(bst_str != "f b h c p") {
            cout << "Incorrect result of removing a. Expected f b h c p but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }

    //bool
    try {
        bool vals[2] = {true, false};
        BST<string, bool> balanced_bst;
        for(int i = 0; i < 2; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(true);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "0") {
            cout << "Incorrect result of removing true. Expected 0 but got : " << bst_str << endl;
        }
        balanced_bst.remove(false);
        bst_str = balanced_bst.to_string();
        if(bst_str != "") {
            cout << "Incorrect result of removing true. Expected empty but got : " << bst_str << endl;
        }
     } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}


void test_max_data() {
    // int
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // float
    try {
        float vals[10] = {5.0, 2.1, 7.2, 1.5, 3.9, 4.5, 6.7, 9.3, 8.5, 10.5};
        BST<float, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], vals[i]);
        }
        float max_str = balanced_bst.max_data();
        if(max_str != 10.5) {
            cout << "Incorrect result of max_data. Expected 10.5 but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // string
    try {
        string vals[10] = {"f", "b", "h", "a", "c", "p", "g", "q", "l", "z"};
        int vals2[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i] + " data", vals2[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "z data") {
            cout << "Incorrect result of max_data. Expected \"z data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // char
    try {
        char vals[10] = {'f', 'b', 'h', 'a', 'c', 'p', 'q', 'l', 'z'};
        BST<char, char> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], vals[i]);
        }
        char max_str = balanced_bst.max_data();
        if(max_str != 'z') {
            cout << "Incorrect result of max_data. Expected z but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // bool  
    try {
        bool vals[10] = {true, false, false, false, false, true, false, true, true, false};
        BST<bool, bool> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], vals[i]);
        }
        bool max_str = balanced_bst.max_data();
        if(max_str != 1) {
            cout << "Incorrect result of max_data. Expected \"1 data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key() {
    // int
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }

    // float
    try {
        float vals[10] = {5.0, 2.1, 7.2, 1.1, 3.9, 4.5, 6.7, 9.3, 8.5, 10.5};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        float max_float = balanced_bst.max_key();
        if(max_float != 10.5) {
            cout << "Incorrect result of max_key. Expected 10.1 but got : " << max_float << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // string
    try {
        string vals[10] = {"f", "b", "h", "a", "c", "p", "g", "q", "l", "z"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i] + " data", vals[i]);
        }
        string max_str = balanced_bst.max_key();
        if(max_str != "z") {
            cout << "Incorrect result of max_key. Expected z but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // char
    try {
        char vals[10] = {'f', 'b', 'h', 'a', 'c', 'p', 'q', 'l', 'z', 'a'};
        BST<string, char> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        char max_str = balanced_bst.max_key();
        if(max_str != 'z') {
            cout << "Incorrect result of max_key. Expected \"z\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    // bool  
    try {
        bool vals[10] = {true, false, false, false, false, true, false, true, true, false};
        BST<string, bool> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        bool max_str = balanced_bst.max_key();
        if(max_str != 1) {
            cout << "Incorrect result of max_key. Expected \"1\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_min_data() {
    //string
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // float
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<float, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i]+0.5, vals[i]);
        }
        float min_str = balanced_bst.min_data();
        if(min_str != 1.5) {
            cout << "Incorrect result of min_data. Expected 1.5 but got : " << min_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // int
    try {
        int vals[10] = {5,2,3,4,8,9,2,1,11,15};
        BST<int, string> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], to_string(vals[i]));
        }
        int max_str = balanced_bst.min_data();
        if(max_str != 1) {
            cout << "Incorrect result of max_data. Expected 1 but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // char 
    try {
        char vals[10] = {'f', 'b', 'h', 'a', 'c', 'p', 'q', 'l', 'z'};
        int vals2[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<char, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], vals2[i]);
        }
        char max_str = balanced_bst.min_data();
        if(max_str != 'a') {
            cout << "Incorrect result of min_data. Expected a but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // bool  
    try {
        bool vals[10] = {true, false, false, false, false, true, false, true, true, false};
        int vals2[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<bool, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i], vals2[i]);
        }
        bool max_str = balanced_bst.min_data();
        if(max_str != 0) {
            cout << "Incorrect result of min_data. Expected 0 but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }

    // float
    try {
        float vals[10] = {5.3, 2.1, 7.2, 1.5, 3.9, 4.5, 6.7, 9.3, 8.5, 10.1};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        float max_float = balanced_bst.min_key();
        if(max_float != 1.5) {
            cout << "Incorrect result of min_key. Expected 1.5 but got : " << max_float << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // string
    try {
        string vals[10] = {"ff", "bb", "hh", "aa", "cc", "pp", "gg", "qq", "ll", "zz"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i] + " data", vals[i]);
        }
        string max_str = balanced_bst.min_key();
        if(max_str != "aa") {
            cout << "Incorrect result of min_key. Expected aa but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // char
    try {
        char vals[10] = {'f', 'b', 'h', 'a', 'c', 'p', 'q', 'l', 'z', 'x'};
        BST<string, char> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        char max_str = balanced_bst.min_key();
        if(max_str != 'a') {
            cout << "Incorrect result of min_key. Expected \"a\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }

    // bool  
    try {
        bool vals[10] = {true, false, false, false, false, true, false, true, true, false};
        BST<string, bool> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        bool max_str = balanced_bst.min_key();
        if(max_str != 0) {
            cout << "Incorrect result of min_key. Expected \"0\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_successor() {
    //int
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if(succ != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if(succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

    //float
    try {
        float vals[10] = {5.5, 2.5, 7.5, 1.5, 3.5, 4.5, 6.5, 9.5, 8.5, 10.5};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        float succ = balanced_bst.successor(4.5);
        if(succ != 5.5) {
            cout << "Incorrect result of successor of 4.5. Expected 5.5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7.5);
        if(succ != 8.5) {
            cout << "Incorrect result of successor of 7.5. Expected 8.5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10.5);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10.5. Expected 0 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

    //string
    try {
        string vals[10] = {"dd", "gg", "ee", "aa", "cc", "bb", "mm", "ff", "pp", "hh"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(vals[i] + " data", vals[i]);
        }
        string succ = balanced_bst.successor("dd");
        if(succ != "ee") {
            cout << "Incorrect result of successor of dd. Expected ee but got : " << succ << endl;
        }
        succ = balanced_bst.successor("bb");
        if(succ != "cc") {
            cout << "Incorrect result of successor of bb. Expected cc but got : " << succ << endl;
        }
        succ = balanced_bst.successor("hh");
        if(succ != "mm") {
            cout << "Incorrect result of successor of hh. Expected mm but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

    //char
    try {
        char vals[10] = {'d', 'g', 'e', 'a', 'c', 'b', 'm', 'f', 'p', 'h'};
        BST<string, char> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        char succ = balanced_bst.successor('d');
        if(succ != 'e') {
            cout << "Incorrect result of successor of d. Expected e but got : " << succ << endl;
        }
        succ = balanced_bst.successor('b');
        if(succ != 'c') {
            cout << "Incorrect result of successor of b. Expected c but got : " << succ << endl;
        }
        succ = balanced_bst.successor('h');
        if(succ != 'm') {
            cout << "Incorrect result of successor of h. Expected m but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

    //bool
    try {
        bool vals[3] = {true, false, true};
        BST<string, char> balanced_bst;
        for(int i = 0; i < 3; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        bool succ = balanced_bst.successor(false);
        if(succ != 1) {
            cout << "Incorrect result of successor of false. Expected 1 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(true);
        if(succ != 1) {
            cout << "Incorrect result of successor of true. Expected 1 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

}

void test_in_order() {
    //int
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }

    //float
    try {
        BST<string, float> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i+0.5);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5") {
            cout << "Incorrect in_order result after inserting keys 1.5-10.5 in order. Expected 1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5 but got : " << bst_str << endl;
        }
        float vals[10] = {5.5, 2.5, 7.5, 1.5, 3.5, 4.5, 6.5, 9.5, 8.5, 10.5};
        BST<string, float> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5") {
            cout << "Incorrect in_order result after inserting keys {5.5, 2.5, 7.5, 1.5, 3.5, 4.5, 6.5, 9.5, 8.5, 10.5}. Expected 1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }

    //string
    try {
        BST<string, string> bst;
        string vals[5] = {"aa", "bb", "cc", "dd", "ee"};
        for(int i = 0; i < 5; i++) {
            bst.insert("some data", vals[i]);
        }
        string bst_str = bst.in_order();
        if(bst_str != "aa bb cc dd ee") {
            cout << "Incorrect in_order result after inserting keys aa-ee in order. Expected aa bb cc dd ee but got : " << bst_str << endl;
        }
        string vals2[5] = {"dd", "aa", "cc", "ee", "ff"};
        BST<string, string> balanced_bst;
        for(int i = 0; i < 5; i++) {
            balanced_bst.insert("some data", vals2[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "aa cc dd ee ff") {
            cout << "Incorrect in_order result after inserting keys {dd, aa, cc, ee, ff}. Expected aa cc dd ee ff but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim() {
    //int
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }

    //float
    try {
        BST<string,float> bst;
        float vals[3] = {1.5, 0.5, 2.5};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1.5,2.5);
        string bst_str = bst.to_string();
        if(bst_str != "1.5 2.5") {
            cout << "Incorrect tree after trimming 1.5 0.5 2.5 with low=1.5, high=2.5. Expected 1.5 2.5 but got : " << bst_str << endl;
        }
        BST<string, float> bst2;
        float vals2[5] = {3.5, 0.5, 4.5, 2.5, 1.5};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1.5,3.5);
        bst_str = bst2.to_string();
        if(bst_str != "3.5 2.5 1.5") {
            cout << "Incorrect tree after trimming 3.5 0.5 4.5 2.5 1.5 with low=1.5, high=3.5. Expected 3.5 2.5 1.5 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }

    //string
    try {
        BST<string,string> bst;
        string vals[3] = {"bb", "aa", "cc"};
        for(int i = 0; i < 3; i++) {
            bst.insert(vals[i]+" data", vals[i]);
        }
        bst.trim("bb", "cc");
        string bst_str = bst.to_string();
        if(bst_str != "bb cc") {
            cout << "Incorrect tree after trimming bb aa cc with low=bb, high=cc. Expected bb cc but got : " << bst_str << endl;
        }
        BST<string, string> bst2;
        string vals2[5] = {"dd", "aa", "ee", "cc", "bb"};
        for(int i = 0; i < 5; i++) {
            bst2.insert(vals2[i]+" data", vals2[i]);
        }
        bst2.trim("bb", "dd");
        bst_str = bst2.to_string();
        if(bst_str != "dd cc bb") {
            cout << "Incorrect tree after trimming dd aa ee cc bb with low=bb, high=dd. Expected dd cc bb but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }

    //char
    try {
        BST<string,char> bst;
        char vals[3] = {'b', 'a', 'c'};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim('b', 'c');
        string bst_str = bst.to_string();
        if(bst_str != "b c") {
            cout << "Incorrect tree after trimming b a c with low=b, high=c. Expected b c but got : " << bst_str << endl;
        }
        BST<string, char> bst2;
        char vals2[5] = {'d', 'a', 'e', 'c', 'b'};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim('b', 'd');
        bst_str = bst2.to_string();
        if(bst_str != "d c b") {
            cout << "Incorrect tree after trimming d a e c b with low=bb, high=dd. Expected d c b but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }

    //bool

    //string
    try {
        BST<string,bool> bst;
        bool vals[2] = {true, false};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(true, true);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect tree after trimming true false with low=true, high=true. Expected 1 but got : " << bst_str << endl;
        }
        BST<string, bool> bst2;
        bool vals2[5] = {true, true, false, false, true};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(false, false);
        bst_str = bst2.to_string();
        if(bst_str != "0 0") {
            cout << "Incorrect tree after trimming true, true, false, false, true with low=false, high=false. Expected 0 0 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_binhex(){
    try {
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

        if(hex1!=expected_hex1) {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
        string bin2 = "110101";
        string expected_hex2 = "35";

        string hex2 = convert<string,string>(bst2, bin2);
        delete bst2;

        if(hex2!=expected_hex2) {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}

int main() {
    
    test_empty();
    test_insert();
    test_get();
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    test_trim();
    test_binhex();

    cout << "Testing completed" << endl;
    
    return 0;
}
