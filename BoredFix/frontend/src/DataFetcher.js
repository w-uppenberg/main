import React from 'react';
import Game from './Game'; 
import './DataFetcher.css'; // Import CSS file

class DataFetcher extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      games: [],
      idN: 0,
      loading: true,
      error: null,
    };
    this.sendGetReq = this.sendGetReq.bind(this);
  }

  async sendGetReq(){
    try {
      const response = await fetch('http://127.0.0.1:5000/games');
      const gamesJson = await response.json();
      var newGames = [];
      for(var i = 0; i < gamesJson.games.length; i++) {
        const game = new Game(gamesJson.games[i].title, gamesJson.games[i].creator, gamesJson.games[i].retail_price);
        newGames.push(game);
      }
      const idN = newGames.length; // Adjusted to reflect the new structure
      this.setState({ games: newGames, idN: idN, loading: false });
    } catch(err) {
      this.setState({ error: err, loading: false });
      console.log(err);
    }
  }

  async componentDidMount() {
    await this.sendGetReq();
  }

  render() {
    const { games, loading, error } = this.state;
    
    if (loading) {
      return <div>Loading...</div>;
    }
    
    if (error) {
      return <div>Error! - {error.message}</div>;
    }
    
    const SendButton  = class extends React.Component {
      
      sendPostReq(title) { 
        try {
          fetch("http://127.0.0.1:5000/games", {
            method: "POST",
            body: JSON.stringify({
              title: title,
              creator: 'Monopol',
              retail_price: 500 // Default value for retail_price
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
        this.sendPostReq(this.props.value);
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
              <th>Game name</th>
              <th>Creator</th>
              <th>Retail Price</th>
            </tr>
          </thead>
          <tbody>
          {games.map((game, index) => (
            <tr key={index}>
              <td>{game.title}</td>
              <td>{game.creator}</td>
              <td>{game.retail_price}</td>
            </tr>
          ))}
          </tbody>
        </table>
      </div>
    );
  }
}

export default DataFetcher;