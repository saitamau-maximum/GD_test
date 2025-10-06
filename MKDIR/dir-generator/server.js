const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const archiver = require('archiver');

const app = express();
app.use(bodyParser.json());
app.use(express.static('public'));

// ディレクトリとファイルを生成する関数
const createDirectoryStructure = (basePath, structure) => {
    const lines = structure.split('\n');
    lines.forEach(line => {
        const trimmedLine = line.trim();
        if (trimmedLine) {
            const relativePath = trimmedLine.replace(/\/$/, '');
            const fullPath = path.join(basePath, relativePath);

            if (trimmedLine.endsWith('/')) {
                fs.mkdirSync(fullPath, { recursive: true });
            } else {
                const dir = path.dirname(fullPath);
                fs.mkdirSync(dir, { recursive: true });
                fs.writeFileSync(fullPath, '');
            }
        }
    });
};

// ZIPファイルを生成する関数
const createZip = (sourceDir, outPath) => {
    return new Promise((resolve, reject) => {
        const output = fs.createWriteStream(outPath);
        const archive = archiver('zip', { zlib: { level: 9 } });

        output.on('close', () => resolve());
        archive.on('error', err => reject(err));

        archive.pipe(output);
        archive.directory(sourceDir, false);
        archive.finalize();
    });
};

// API エンドポイント
app.post('/api/generate-zip', async (req, res) => {
    const structure = req.body.structure;
    const outputDir = path.join(__dirname, 'output');
    const zipPath = path.join(__dirname, 'output.zip');

    // 既存のディレクトリとZIPを削除
    fs.rmSync(outputDir, { recursive: true, force: true });
    fs.rmSync(zipPath, { force: true });

    try {
        createDirectoryStructure(outputDir, structure);
        await createZip(outputDir, zipPath);

        res.json({ downloadUrl: '/output.zip' });
    } catch (error) {
        res.status(500).json({ message: 'エラーが発生しました。', error });
    }
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`サーバーが http://localhost:${PORT} で起動しました`);
});
