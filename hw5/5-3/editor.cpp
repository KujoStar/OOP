#include <algorithm>
#include <cstdio>

#include "editor.h"

#define vCur data[cur.first]
#define vL data[L.first]
#define vR data[R.first]
#define lCur vCur.substr(0, cur.second)
#define rCur vCur.substr(cur.second)

TextEditor::TextEditor(): data(1), clipboard(0), cur({0, 0}), L(Null), R(Null) { }

void TextEditor::removeLines(int now, int length) {
  if (length <= 0)
    return;
  for (int i = now + 1; i < data.size() - length; i++)
    data[i].swap(data[i + length]);
  data.resize(data.size() - length);
}

void TextEditor::insertLines(int now, int length) {
  if (length <= 0)
    return;
  data.resize(data.size() + length);
  for (int i = data.size() - 1 - length; i > now; i--)
    data[i].swap(data[i + length]);
}

void TextEditor::remove() {
  if (L == Null || R == Null) return;
  vL = vL.substr(0, L.second) + vR.substr(R.second);
  removeLines(L.first, R.first - L.first);
  cur = L, L = R = Null;
}

void TextEditor::moveCursor(Position dest) {
  cur = dest, L = R = Null;
}

void TextEditor::select(Position beg, Position end) {
  L = beg, R = end, cur = Null;
}

void TextEditor::write(const std::string& str) {
  remove(), vCur = lCur + str + rCur, cur.second += str.length();
}

void TextEditor::newline() {
  remove(), insertLines(cur.first, 1);
  data[cur.first + 1] = data[cur.first].substr(cur.second);
  vCur = lCur;
  cur.first ++, cur.second = 0;
}

void TextEditor::del() {
  if (L != Null && R != Null)
    remove();
  else if (cur.second < vCur.length())
    vCur.erase(cur.second, 1);
  else if (cur.first != data.size() - 1) {
    vCur += data[cur.first + 1];
    removeLines(cur.first, 1);
  }
}

void TextEditor::copy() {
  if (L == Null || R == Null)
    return;
  int length = R.first - L.first + 1;
  clipboard.resize(length);
  if (length == 1) {
    clipboard.front() = vL.substr(L.second, R.second - L.second);
    return;
  }
  clipboard.front() = vL.substr(L.second);
  clipboard.back() = vR.substr(0, R.second);
  std::copy(data.begin() + L.first + 1, data.begin() + R.first, clipboard.begin() + 1);
}

void TextEditor::paste() {
  remove();
  int length = clipboard.size();
  if (length == 0)
    return;
  if (length == 1) {
    vCur = lCur + clipboard.front() + rCur;
    cur.second += clipboard.front().length();
    return;
  }
  insertLines(cur.first, length - 1);
  std::copy(clipboard.begin() + 1, clipboard.end() - 1, data.begin() + cur.first + 1);
  data[cur.first + length - 1] = clipboard.back() + rCur; 
  vCur = lCur + clipboard.front();
  cur.first += length - 1, cur.second = clipboard.back().length();
}

void TextEditor::screenShot() {
  Position p({0, 0});
  while (p.first < data.size()) {
    if (p == L) putchar('*');
    if (p == R) putchar('*');
    if (p == cur) putchar('*');
    if (p.second == data[p.first].length()) {
      p.first ++, p.second = 0;
      if (p.first != data.size())
        putchar('\n');
    }
    else putchar(data[p.first][p.second++]);
  }
}
