# Three.js vs GLM (C++) 对照指南

作为从 Three.js 转过来的开发者，最需要适应的就是数学库的变化。在 C++ OpenGL 开发中，我们通常使用 **GLM (OpenGL Mathematics)** 库，它的设计初衷就是模仿 GLSL 的语法，所以用起来会比 Three.js 的数学库更像 Shader 代码。

## 1. 向量 (Vectors)

### Three.js
```javascript
const v = new THREE.Vector3(1.0, 2.0, 3.0);
const u = new THREE.Vector3(0.0, 1.0, 0.0);
const w = v.add(u); 
```

### GLM (C++)
```cpp
#include <glm/glm.hpp>

glm::vec3 v(1.0f, 2.0f, 3.0f);
glm::vec3 u(0.0f, 1.0f, 0.0f);
glm::vec3 w = v + u; // GLM 支持运算符重载，写法更直观
```

## 2. 矩阵 (Matrices) & 变换 (Transforms)

在 Three.js 中，`Mesh` 自动维护了 `position`, `rotation`, `scale` 并计算 `matrixWorld`。
在 C++ 中，我们需要手动构建 Model 矩阵。

### Three.js (自动)
```javascript
mesh.position.set(1, 0, 0);
mesh.rotation.y = Math.PI / 4;
mesh.scale.set(2, 2, 2);
// 内部自动计算 modelMatrix
```

### GLM (手动构建)
```cpp
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// 初始化单位矩阵
glm::mat4 model = glm::mat4(1.0f); 

// 1. 位移 (Translate)
model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));

// 2. 旋转 (Rotate) - 注意需要传入弧度和旋转轴
model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

// 3. 缩放 (Scale)
model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
```

## 3. 摄像机 (Camera)

Three.js 的 `PerspectiveCamera` 帮我们计算了 Projection 和 View 矩阵。C++ 里我们要自己算。

### Three.js
```javascript
const camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 100);
camera.position.set(0, 0, 3);
camera.lookAt(0, 0, 0);
```

### GLM
```cpp
// Projection Matrix (投影矩阵)
// fov (弧度), aspect ratio, near, far
glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

// View Matrix (视图矩阵) - 也就是 LookAt
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
```

## 4. 传给 Shader

### Three.js
Three.js 自动上传 `projectionMatrix`, `modelViewMatrix` 等 uniform。

### C++ (使用我们封装的 Shader 类)
```cpp
#include <glm/gtc/type_ptr.hpp> // 包含 value_ptr

unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
unsigned int projLoc  = glGetUniformLocation(ourShader.ID, "projection");

// glUniformMatrix4fv(location, count, transpose, value_ptr)
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
```
