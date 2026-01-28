# 编译器
CXX = g++
# 编译选项: -I 指定头文件路径
CXXFLAGS = -std=c++11 -Wall -I./libs/include

# 链接选项: -L 指定库文件路径
# Windows MinGW 需要链接的库:
# -lglew32: GLEW (使用 DLL 版本)
# -lglfw3dll: GLFW (使用 DLL 版本，解决 MinGW 版本不兼容问题)
# -lopengl32: OpenGL 核心
# -lgdi32, -luser32, -lkernel32: Windows 系统库
LDFLAGS = -L./libs/lib -lglew32 -lglfw3dll -lopengl32 -lgdi32 -luser32 -lkernel32

# 目标文件名 (Windows 下通常是 .exe)
TARGET = hello_opengl.exe

# 源文件
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
