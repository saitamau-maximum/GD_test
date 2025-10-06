const fs = require('fs');
const path = require('path');

function createDirectory(dirPath) {
  if (!fs.existsSync(dirPath)) {
    fs.mkdirSync(dirPath, { recursive: true });// Create the directory recursively
    console.log(`Directory created: ${dirPath}`);
  } else {
    console.log(`Directory already exists: ${dirPath}`);
  }
}

// 使用例
createDirectory(path.join(__dirname, 'exampleDir'));
// This script creates a directory if it does not already exist.
// You can change 'exampleDir' to any directory name you want to create.