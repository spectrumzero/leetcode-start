#!/bin/bash

# 获取 CMakeLists.txt 中的可执行文件路径
getExePathFromCMakeLists() {
  local content
  local exeName=""

  content=$(cat "./CMakeLists.txt")

  while IFS= read -r line; do
    if [[ $line == add_executable* ]]; then
      local index=$(echo $line | grep -b -o '(' | cut -d: -f1)
      exeName=$(echo $line | cut -d' ' -f2)
      break
    fi
  done <<<"$content"

  # 构造可执行文件路径
  local exePath="./build/$exeName"
  echo "$exePath"
}

# 获取当前目录
currentDirectory=$(pwd)
cmakeListsPath="$currentDirectory/CMakeLists.txt"

# 检查 CMakeLists.txt 是否存在
if [ ! -f "$cmakeListsPath" ]; then
  echo "No CMakeLists.txt in current directory, please check."
  exit 1
fi

echo "Start generating and compiling..."

# 设置 build 文件夹路径
buildFolderPath="./build"

# 如果 build 文件夹不存在，则创建它
if [ ! -d "$buildFolderPath" ]; then
  mkdir "$buildFolderPath"
  echo "build folder created."
fi

# 运行 CMake 生成项目
cmake -G "Unix Makefiles" -S . -B ./build/
if [ $? -eq 0 ]; then
  # 编译项目
  cmake --build ./build/
  if [ $? -eq 0 ]; then
    # 获取可执行文件路径
    exePath=$(getExePathFromCMakeLists)
    echo "start running as follows..."
    echo "=================================================="
    # 运行可执行文件
    # if [ -f "$exePath" ]; then
    ./build/leetcode-start
    # else
    # echo "Executable not found: ./build/leetcode-start"
    # exit 1
    # fi
  else
    echo "Build failed."
    exit 1
  fi
else
  echo "CMake generation failed."
  exit 1
fi
