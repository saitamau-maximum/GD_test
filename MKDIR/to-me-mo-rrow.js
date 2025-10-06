// 画像の一括ダウンロード
async function downloadImages() {
    // 画像 URL
    const sources = [].slice.call(
      document.querySelectorAll("#section_banner img")
    ).map(img => img.getAttribute("src"));
  
    // JSZip に追加するために非同期リクエストを Promise で wrap
    const imagePromises = sources.map(
      (src, i) => new Promise((resolve, reject) => {
        let xhr = new XMLHttpRequest();
        xhr.open('GET', src, true);
        xhr.responseType = "blob";
        xhr.onload = function() {
          // ファイル名とデータ返却
          const fileName = src.slice(src.lastIndexOf("/") + 1);
          resolve({ data: this.response, fileName: fileName });
        };
        // reject だと await Promise.all を抜けてしまう
        // => resolve でデータ無し
        xhr.onerror = () => resolve({ data: null });
        xhr.onabort = () => resolve({ data: null });
        xhr.ontimeout = () => resolve({ data: null });
        xhr.send();
      })
    );
  
    // すべての画像が取得できたら zip 生成
    const images = await Promise.all(imagePromises);
    generateImagesZip(images);
  }