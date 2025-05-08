from flask import Flask, jsonify, request
from flask_cors import CORS
import Game

app = Flask (__name__)
games = []  # List to store game objects
CORS(app)

@app.route('/games', methods=['POST'])
def add_game():
    new_game_json = request.get_json()  # Parse the incoming JSON data
    new_game = Game(new_game_json['title'], new_game_json['creator'], new_game_json['retail_price'])
    # Create a new Game object using the parsed data
    games.append(new_game)  # Add the new game to the games 
    response = jsonify({'message': 'game added successfully', 'games': games})
    return response

@app.route('/games', methods=['GET'])
def get_games():
        response = jsonify({'games': games})
        return response

if __name__ == '__main__':
    app.run(debug=True)


