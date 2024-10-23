class Book {
    constructor(id, title, author) {
        this.id = id;
        this.title = title;
        this.author = author;
    }

    present() {
        return 'Book: ' + this.title + ' by ' + this.author;
    }
}

export default Book;