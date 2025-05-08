class Game {
    constructor(title, creator, retail_price) {
        this.title = title;
        this.creator = creator;
        this.retail_price = retail_price;
        }

    present() {
        return 'Game: ' + this.title + ' by ' + this.creator + ' for ' + this.retail_price + ' SEK.';
    }
}

export default Game;