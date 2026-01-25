# 编译器
CXX = g++
# 编译选项
CXXFLAGS = -std=c++11 -Wall

# 链接库 (Linux 下开发 OpenGL 通常需要这些库)
# -lGL: OpenGL 核心库
# -lGLEW: 管理 OpenGL 函数指针
# -lglfw: 窗口管理库
# -ldl -lpthread: 系统依赖
LDFLAGS = -lGL -lGLEW -lglfw -ldl -lpthread

# 目标文件名
TARGET = hello_opengl

# 源文件
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
