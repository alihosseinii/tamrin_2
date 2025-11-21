#ifndef tiktaktoe_hpp
#define tiktaktoe_hpp

class tiktaktoe {
private:
char board[9] {' ',' ',' ',' ',' ',' ',' ',' ',' '};  
char player {'X'};

public:
    void display() const;
    void play();
    bool iswiner()const;
    bool isposible(int n) const;
    bool isfull(int n) const;
    bool isdrwa() const;
    void switchplayer();


};

#endif