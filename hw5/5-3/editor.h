#pragma once

#include <vector>
#include <string>
#include <list>

class TextEditor {
private:
    using Position = std::pair<int, int>;
    const Position Null = {-1, -1};
    Position cur;
    Position L, R;
    std::vector<std::string> data; // 数据区，亦可采用其他数据结构
    std::vector<std::string> clipboard; // 剪贴板，亦可采用其他数据结构
    void remove();
    void removeLines(int now, int length);
    void insertLines(int now, int length);
public:
    TextEditor();
    void moveCursor(Position dest);
    void select(Position beg, Position end);
    void write(const std::string& str);
    void newline();
    void del();
    void copy();
    void paste();
    void screenShot();
};