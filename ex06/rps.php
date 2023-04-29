<?php

$choices = array('rock', 'paper', 'scissors');

$user_choice = readline("Choose rock, paper, or scissors: ");
while ($user_choice != "rock" && $user_choice != "paper" && $user_choice != "scissors")
  $user_choice = readline("wrong input \nChoose rock, paper, or scissors: ");

$computer_choice = $choices[rand(0,2)];

if ($user_choice == $computer_choice) {
  echo "It's a tie!";
} elseif (($user_choice == 'rock' && $computer_choice == 'scissors') || ($user_choice == 'paper' && $computer_choice == 'rock') || ($user_choice == 'scissors' && $computer_choice == 'paper')) {
  echo "Congratulations! You won! The computer chose $computer_choice.";
} else {
  echo "Sorry, You lost. The computer chose $computer_choice.";
}

?>