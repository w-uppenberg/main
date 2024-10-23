import React from 'react';
import Book from './Book'; 
import './DataFetcher.css'; // Import CSS file

class DataFetcher extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      books: [],
      idN: 0,
      loading: true,
      error: null,
    };
    this.sendGetReq = this.sendGetReq.bind(this);
  }

  
  async sendGetReq(){
    try {
      const response = await fetch('http://127.0.0.1:5000/books');
      const booksJson = await response.json();
      var newBooks = [];
      for(var i = 0; i < booksJson.books.length; i++) {
        const book = new Book(booksJson.books[i].id, booksJson.books[i].title, booksJson.books[i].author);
        newBooks.push(book);
      }
      const idN = newBooks[booksJson.books.length-1].id + 1;
      this.setState({ books: newBooks, idN: idN, loading: false });
    } catch(err) {
      this.setState({ error: err, loading: false });
      console.log(err);
    }
  }

  async componentDidMount() {
    await this.sendGetReq();
  }

  render() {
    
    const { books, loading, idN, error } = this.state;
    
    if (loading) {
      return <div>Loading...</div>;
    }
    
    if (error) {
      return <div>Error! - {error.message}</div>;
    }
    
    const SendButton  = class extends React.Component {
      
      sendPostReq(title, id) { 
        try {
          fetch("http://127.0.0.1:5000/books", {
            method: "POST",
            body: JSON.stringify({
              id: id,
              title: title,
              author: 'Gustav W. Uppenberg'
            }),
            headers: {
              "Content-type": "application/json; charset=UTF-8",
              'Access-Control-Allow-Origin': '*'
            }
          });
        } catch(err) {
          console.log(err);
        }
      }

      onClick = () => {
        this.sendPostReq(this.props.value, this.props.id);
      }

      render() {
        return (
          <button className="action-button" onClick={this.onClick}>
            {this.props.value}      
          </button>
        );
      }
    }

    return (
      <div className="container">
        <img src="/sunflower_header_2.jpg" alt="Header Image" className="header-image" />
        <h1 className="header-text">Test Framework - v1.0.1-ALPHA</h1>
        <div className="button-group">
          <SendButton value = 'Fantastic' id = {this.state.idN} />
          <SendButton value = 'Excellent' id = {this.state.idN}/>
          <SendButton value = 'Tree' id = {this.state.idN}/>
        </div>
        <table className="data-table">
          <thead>
            <tr>
              <th>Test run</th>
              <th>Test name</th>
              <th>Test responsible</th>
            </tr>
          </thead>
          <tbody>
          {books.map((book, index) => (
            <tr key={index}>
              <td>{book.id}</td>
              <td>{book.title}</td>
              <td>{book.author}</td>
            </tr>
          ))}
          </tbody>
        </table>
      </div>
    );
  }
}

export default DataFetcher;