pros_names(pros) {
  		 if (!pros) { return "       none"; }
  if (pros > 0 && pros < 5) { return "     rotten"; }
 if (pros > 4 && pros < 10) { return "     feeble"; }
 if (pros > 9 && pros < 15) { return "  very poor"; }
if (pros > 14 && pros < 20) { return "       poor"; }
if (pros > 19 && pros < 25) { return "       weak"; }
if (pros > 24 && pros < 30) { return "      lousy"; }
if (pros > 29 && pros < 35) { return "        low"; }
if (pros > 34 && pros < 40) { return "  quite low"; }
if (pros > 39 && pros < 45) { return "   adequate"; }
if (pros > 44 && pros < 50) { return "    average"; }
if (pros > 49 && pros < 55) { return "   mediocre"; }
if (pros > 54 && pros < 60) { return "       fair"; }
if (pros > 59 && pros < 65) { return "       nice"; }
if (pros > 64 && pros < 70) { return " quite good"; }
if (pros > 69 && pros < 75) { return "       good"; }
if (pros > 74 && pros < 80) { return "  very good"; }
if (pros > 79 && pros < 85) { return "      great"; }
if (pros > 84 && pros < 90) { return "  marvelous"; }
if (pros > 89 && pros < 95) { return "magnificent"; }
if (pros > 94 && pros < 100) {return "     superb"; }
	   if (pros == 100) { return "outstanding"; }
}

adjectives(str) {
  if (str == "feeble") { return 5; }
  if (str == "very poor") { return 10; }
  if (str == "poor") { return 15; }
  if (str == "weak") { return 20; }
  if (str == "lousy") { return 25; }
  if (str == "low") { return 30; }
  if (str == "quite low") { return 35; }
  if (str == "adequate") { return 40; }
  if (str == "average") { return 45; }
  if (str == "mediocre") { return 50; }
  if (str == "fair") { return 55; }
  if (str == "nice") { return 60; }
  if (str == "quite good") { return 65; }
  if (str == "good") { return 70; }
  if (str == "very good") { return 75; }
  if (str == "great") { return 80; }
  if (str == "marvelous") { return 85; }
  if (str == "magnificent") { return 90; }
  if (str == "superb") { return 95; }
  if (str == "outstanding") { return 100; }
}

