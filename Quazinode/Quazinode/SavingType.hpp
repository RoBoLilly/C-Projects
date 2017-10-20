//
//  SavingType.hpp
//  SDLTesting
//
//  Created by Lilly Fiorino on 8/6/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef SavingType_hpp
#define SavingType_hpp

#include <stdio.h>
#include <string>

using namespace std;

class SavingType {
protected:
    string fileName;
public:
    SavingType(string name);
    void setFileName(string name);
    string getFileName();
    bool write();
    bool read();
};

class LineIndexType : protected SavingType{
protected:
    LineIndexType(string name, int index);
    int dataIndex;
};

class S_data : public LineIndexType {
private:
    int data;
public:
    S_data(std::string name, int index);
    void setDataIndex(int i);
    int getDataIndex();
    void set(int i);
    int get();
    void Wset(int i);
    int Rget();
    bool write();
    bool read();
};
#endif /* SavingType_hpp */
