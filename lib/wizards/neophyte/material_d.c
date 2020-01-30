get_weapon_material(int i) {
	switch(i) {
		      case 0: return "bone";
			  case 1: return "wood";
			  case 2: return "brass";
			  case 3: return "bronze";
			  case 4: return "copper";
			  case 5: return "silver";
			  case 6: return "platinium";
			  case 7: return "iron";
			  case 8: return "steel";
			  case 9: return "mithril";
			  case 10: return "adamantium";
}
return "magic";
}
query_material_value(str) {
	switch(str) {
						case "bone": return 1;
						case "wood": return 2;
						case "brass": return 3;
						case "bronze": return 4;
						case "copper": return 5;
						case "silver": return 6;
						case "platinum": return 7;
						case "iron": return 8;
						case "steel": return 9;
						case "mithril": return 10;
						case "adamantium": return 11;
}
return 1;
}
query_valid_material(str) {
	switch(str) {
				case "bone": return 1;
				case "wood": return 1;
				case "brass": return 1;
				case "bronze": return 1;
				case "copper": return 1;
				case "silver": return 1;
				case "platinum": return 1;
				case "iron": return 1;
				case "steel": return 1;
				case "mithril": return 1;
				case "adamantium": return 1;
}
return 0;
}
query_material_weight(str) {
	switch(str) {
		case "bone": return 3;
		case "wood": return 4;
		case "brass": return 5;
		case "bronze": return 5;
		case "copper": return 5;
		case "silver": return 9;
		case "platinum": return 7;
		case "iron": return 6;
		case "steel": return 5;
		case "mithril": return 3;
		case "adamantium": return 4;
	}
	return 2;
}