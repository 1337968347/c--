$ErrorActionPreference = "Stop"

$libsDir = "$PSScriptRoot\libs"
$includeDir = "$libsDir\include"
$libDir = "$libsDir\lib"

# Create directories
New-Item -ItemType Directory -Force -Path $includeDir | Out-Null
New-Item -ItemType Directory -Force -Path $libDir | Out-Null

Write-Host "Downloading dependencies..."

# 1. GLFW
$glfwUrl = "https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN32.zip"
$glfwZip = "$libsDir\glfw.zip"
Invoke-WebRequest -Uri $glfwUrl -OutFile $glfwZip
Expand-Archive -Path $glfwZip -DestinationPath $libsDir -Force
$glfwRoot = "$libsDir\glfw-3.3.8.bin.WIN32"
# Copy headers
Copy-Item -Recurse -Force "$glfwRoot\include\GLFW" "$includeDir"
# Copy libs (MinGW)
Copy-Item -Recurse -Force "$glfwRoot\lib-mingw\*" "$libDir"
Write-Host "GLFW installed."

# 2. GLEW
$glewUrl = "https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip"
$glewZip = "$libsDir\glew.zip"
Invoke-WebRequest -Uri $glewUrl -OutFile $glewZip
Expand-Archive -Path $glewZip -DestinationPath $libsDir -Force
$glewRoot = "$libsDir\glew-2.2.0"
# Copy headers
Copy-Item -Recurse -Force "$glewRoot\include\GL" "$includeDir"
# Copy libs
Copy-Item -Recurse -Force "$glewRoot\lib\Release\Win32\*" "$libDir"
# Copy dll to root for running
Copy-Item -Force "$glewRoot\bin\Release\Win32\glew32.dll" "$PSScriptRoot"
Write-Host "GLEW installed."

# 3. GLM
$glmUrl = "https://github.com/g-truc/glm/archive/refs/tags/0.9.9.8.zip"
$glmZip = "$libsDir\glm.zip"
Invoke-WebRequest -Uri $glmUrl -OutFile $glmZip
Expand-Archive -Path $glmZip -DestinationPath $libsDir -Force
$glmRoot = "$libsDir\glm-0.9.9.8"
# Copy headers
Copy-Item -Recurse -Force "$glmRoot\glm" "$includeDir"
Write-Host "GLM installed."

# Cleanup
Remove-Item $glfwZip
Remove-Item $glewZip
Remove-Item $glmZip
Remove-Item -Recurse -Force $glfwRoot
Remove-Item -Recurse -Force $glewRoot
Remove-Item -Recurse -Force $glmRoot

Write-Host "All dependencies installed successfully!"
