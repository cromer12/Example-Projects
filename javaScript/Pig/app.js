var scores, roundScore, activePlayer, previous, previous1, winningScore;

init();

//roll dice event listener
document.querySelector('.btn-roll').addEventListener('click', function(){
    
    // 1. Random Number
    var dice = Math.floor(Math.random() * 6) + 1;
    var dice1 = Math.floor(Math.random() * 6) + 1;
 
    if(dice === 1 && dice1 === 1)
    {
        scores[activePlayer] = 0;
        document.querySelector('#current-' + activePlayer).textContent = 0;
        nextPlayer();
        return;
    }

    // 2. Display Result
    var diceDOM = document.querySelector('.dice');
    var diceDOM1 = document.querySelector('.dice1');
    diceDOM.style.display = 'block';
    diceDOM.src = 'dice-' + dice + '.png';
    diceDOM1.style.display = 'block';
    diceDOM1.src = 'dice-' + dice1 + '.png';

    // 3. Update if not 1
    if(dice !== 1 && dice1 !== 1){
        //Add score
        roundScore += dice;
        roundScore += dice1;
        document.querySelector('#current-' + activePlayer).textContent = roundScore;
    }else{
        //next player
        nextPlayer();
    }
});

//Hold event listner
document.querySelector('.btn-hold').addEventListener('click', function(){
    
    // 1. Sets score
    scores[activePlayer] += roundScore;

    // 2. Reset values and diplay
    roundScore = 0;
    document.querySelector('#score-' + activePlayer).textContent = scores[activePlayer];
    document.querySelector('#current-' + activePlayer).textContent = roundScore;
    
    // 3. Win Check
    if(scores[activePlayer] >= winningScore){
        document.querySelector('#name-' + activePlayer).textContent = 'Winner!';
        document.querySelector('.player-' + activePlayer + '-panel').classList.add('winner');
        document.querySelector('.player-' + activePlayer + '-panel').classList.remove('active');

        document.querySelector('.btn-roll').style.display = 'none';
        document.querySelector('.btn-hold').style.display = 'none';
        document.querySelector('.dice').style.display = 'none';
        document.querySelector('.dice1').style.display = 'none';
    }else{
        // 4. Change Active Player
        nextPlayer();
    }
});

//New Game event listner
document.querySelector('.btn-new').addEventListener('click', init);

// Changes Active Player
function nextPlayer(){
    
    activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
    roundScore = 0;

    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';

    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('.player-1-panel').classList.toggle('active');
    document.querySelector('.dice').style.display = 'none';
    document.querySelector('.dice1').style.display = 'none';
}

// Sets all values to NEWGAME state
function init(){
    // 1. reset values    
    scores = [0,0];
    roundScore = 0;
    activePlayer = 0;
    previous = 0;
    winningScore = 0;
    
    // 2. reset displays
    document.querySelector('.dice').style.display = 'none';
    document.querySelector('.dice1').style.display = 'none';
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.querySelector('.btn-new').innerHTML = '<i class="ion-ios-plus-outline"></i>New game';
    document.querySelector('.btn-roll').style.display = 'block';
    document.querySelector('.btn-hold').style.display = 'block';
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('active');
    document.querySelector('#name-0').textContent = 'Player 1';
    document.querySelector('#name-1').textContent = 'Player 2';
    document.querySelector('.player-0-panel').classList.add('active');
    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('winner');

    winningScore = prompt("Input Winning Score", "100");
    while(winningScore == null || winningScore == "" || !winningScore.match(/[0-9]/) || winningScore <= 0 ){
        winningScore = prompt("Input Winning Score, Numbers Only;", "100");
    }
}

function isNumberKey(evt)
{
   var charCode = (evt.which) ? evt.which : event.keyCode
   if (charCode > 31 && (charCode < 48 || charCode > 57))
      return false;

   return true;
}


