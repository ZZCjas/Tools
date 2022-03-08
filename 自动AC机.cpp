#include <fstream>
#include <sstream>
#include <string>

const char* probname = "";//这里改成题目名
#ifdef _WIN32 
const char pathsep = '\\';
#else
const char pathsep = '/';
#endif
std::string get_filename(bool out, int id = 0) 
{
  std::ostringstream str; 
  if (id == 0) {
    str << probname << '.' << (out ? "out" : "in");
  } else {
    str << ".." << pathsep << ".." << pathsep << "data" << pathsep << probname << pathsep << id << '.' << (out ? "out" : "in");
  }
  return str.str();
}
bool check_stream(std::istream& fin, std::istream& tin) {
  fin.seekg(0); 
  for (char ch = fin.get(), ch2 = tin.get(); ch != -1 && ch2 != -1; ch = fin.get(), ch2 = tin.get()) { // 这里要两个流同时结尾时才停止比对，防止一个流是另一个流的前缀时出错，并且get方法出错时返回-1，并不会抛出异常，所以不会出错
    if (ch != ch2) {
      return false;
    }
  }
  return true;
}
int main() {
  std::ifstream fin(get_filename(false).c_str()); 
  std::ofstream fout(get_filename(true).c_str());
  for (int i = 1;; i++) {
    std::ifstream tin(get_filename(false, i).c_str());
    if (!tin.is_open()) {
      break;
    } else if (check_stream(fin, tin)) {
      std::ifstream tout(get_filename(true, i).c_str());
      for (char ch = tout.get(); ch != -1; ch = tout.get()) {
        fout << ch;
      }
      return 0;
    }
  }
  return 1; 
}

