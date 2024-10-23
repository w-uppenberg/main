from flask import Flask, jsonify, request
from flask_cors import CORS

app = Flask (__name__)
books = [{'id': 1, 'title': 'something', 'author': 'Gustav Uppenberg'}]
CORS(app)

@app.route('/books', methods=['POST'])
def add_book():
    new_book = request.get_json()  # Parse the incoming JSON data
    books.append(new_book)  # Add the new book to the books 
    response = jsonify({'message': 'Book added successfully', 'books': books})
    return response

@app.route('/books', methods=['GET'])
def get_books():
        response = jsonify({'books': books})
        return response

if __name__ == '__main__':
    app.run(debug=True)
