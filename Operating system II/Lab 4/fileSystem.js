class File {
    constructor({name, size = 0}) {
        this.name = name;
        this.size = size;
    }
}

class FileSystem {
    constructor() {
        this.files = [];
    }

    addFile({name, size}) {
        const fileAlreadyExist = this.checkIfFileExists();
        if(fileAlreadyExist) {
            console.error('FILE ALREADY EXIST');
            return;
        }
        const newFile = new File({name, size});
        this.files.push(newFile);
    }

    removeFile(name) {
        const fileIndex = this.findFileIndex(name);
        if(fileIndex === -1) {
            console.error(`FILE DOESN'T EXIST`);
            return;
        }
        this.files.splice(fileIndex, 1);
    }

    findFile(name) {
        return this.files[this.findFileIndex(name)];
    }

    findFileIndex(name) {
        return this.files.findIndex(file => file.name === name);
    }

    renameFile(oldName, newName) {
        const file = this.findFile(oldName);
        const newNameAlreadyExists = this.checkIfFileExists(newName);
        if(newNameAlreadyExists) {
            console.error(`${newName} ALREADY TAKEN`);
            return;
        }
        file.name = newName;
    }

    checkIfFileExists(name) {
        return this.files.some(
        (file) => file.name === name
        );
    }

    displayFiles() {
        console.log(JSON.stringify(this.files, null, 4));
    }

    truncateFile(name) {
        this.writeFile(name, 0);
    }

    writeFile(name, size) {
        const file = this.findFile(name);
        if(!file) {
            console.error(`${name} DOESN'T EXIST`);
            return;
        }
        file.size += size;
    }
}

const fs = new FileSystem();

fs.addFile({name: 'file 1', size: 50});
fs.addFile({name: 'file 2', size: 100});
fs.addFile({name: 'file 3', size: 150});
fs.addFile({name: 'file 4', size: 200});

fs.displayFiles();

fs.removeFile('file 2');
fs.removeFile('file 32');

fs.displayFiles();

fs.renameFile('file 1', 'file 5');

console.log(fs.findFile('file 5'));

fs.displayFiles();

fs.truncateFile('file 5');

fs.displayFiles();

fs.writeFile('file 3', 500);

fs.displayFiles();
