// 1
// var arr = ["B_1", "A_2", "B_3", "B_4", "B_5", "D_6", "D_7", "B_8", "B_9", "B_10", "C_11", "C_12", "B_13", "B_14", "B_15", "C_16", "B_17", "B_18", "B_19", "D_20", "B_21", "C_22", "D_23", "C_24", "D_25", "D_26", "B_27", "C_28", "B_29", "B_30", "A_31", "C_32", "D_33", "B_34", "D_35", "B_36", "C_37", "B_38", "B_39", "B_40", "A_41", "B_42", "D_43", "C_44", "C_45", "D_46", "B_47", "D_48", "C_49", "B_50", "B_51", "B_52", "D_53", "B_54", "B_55", "B_56", "C_57", "A_58", "D_59", "B_60"]
// 2
var arr = ["D_1", "B_2", "D_3", "B_4", "C_5", "C_6", "D_7", "D_8", "C_9", "C_10", "B_11", "B_12", "A_13", "B_14", "C_15", "A_16", "D_17", "C_18", "D_19", "B_20", "C_21", "C_22", "C_23", "D_24", "D_25", "A_26", "A_27", "B_28", "C_29", "D_30", "D_31", "B_32", "B_33", "A_34", "D_35", "A_36", "A_37", "A_38", "B_39", "C_40", "D_41", "D_42", "D_43", "D_44", "C_45", "D_46", "B_47", "D_48", "C_49", "D_50", "D_51", "D_52", "D_53", "A_54", "A_55", "D_56", "D_57", "C_58", "B_59", "B_60"]
// vlsi
// var arr = ["C_1", "B_2", "D_3", "A_4", "B_5", "A_6", "B_7", "A_8", "C_9", "A_10", "D_11", "A_12", "B_13", "C_14", "D_15", "B_16", "A_17", "D_18", "D_19", "C_20", "C_21", "A_22", "B_23", "A_24", "D_25", "A_26", "A_27", "D_28", "C_29", "B_30", "C_31", "C_32", "D_33", "A_34", "B_35", "C_36", "C_37", "B_38", "C_39", "B_40", "D_41", "D_42", "D_43", "D_44", "C_45", "D_46", "B_47", "D_48", "C_49", "D_50", "D_51", "D_52", "D_53", "A_54", "A_55", "D_56", "D_57", "C_58", "B_59", "B_60"]
// edc
// var arr = ["A_1", "D_2", "B_3", "A_4", "D_5", "C_6", "C_7", "B_8", "B_9", "C_10", "D_11", "A_12", "D_13", "B_14", "C_15", "D_16", "A_17", "B_18", "D_19", "B_20", "D_21", "C_22", "C_23", "A_24", "A_25", "C_26", "A_27", "A_28", "D_29", "D_30", "A_31", "C_32", "C_33", "D_34", "C_35", "B_36", "D_37", "C_38", "A_39", "B_40", "D_41", "D_42", "D_43", "D_44", "C_45", "D_46", "B_47", "D_48", "C_49", "D_50", "D_51", "D_52", "D_53", "A_54", "A_55", "D_56", "D_57", "C_58", "B_59", "B_60"]
// EMBEDDED
// var arr = ["A_1", "D_2", "C_3", "B_4", "A_5", "B_6", "A_7", "B_8", "B_9", "A_10", "A_11", "D_12", "C_13", "C_14", "C_15", "B_16", "D_17", "D_18", "C_19", "B_20", "A_21", "A_22", "A_23", "C_24", "D_25", "A_26", "A_27", "C_28", "A_29", "D_30", "B_31", "B_32", "B_33", "D_34", "A_35", "B_36", "C_37", "B_38", "D_39", "D_40", "A_41", "D_42", "C_43", "B_44", "A_45", "B_46", "A_47", "B_48", "B_49", "A_50", "A_51", "D_52", "C_53", "C_54", "C_55", "B_56", "D_57", "D_58", "C_59", "B_60"]
// cnw
// var arr = ["D_1", "D_2", "A_3", "C_4", "A_5", "A_6", "B_7", "B_8", "A_9", "C_10", "A_11", "D_12", "C_13", "B_14", "A_15", "B_16", "A_17", "B_18", "B_19", "A_20", "D_21", "B_22", "A_23", "C_24", "A_25", "A_26", "A_27", "A_28", "C_29", "B_30", "B_31", "B_32", "B_33", "D_34", "A_35", "B_36", "C_37", "B_38", "D_39", "D_40", "D_41", "D_42", "A_43", "C_44", "A_45", "A_46", "B_47", "B_48", "A_49", "C_50", "A_51", "D_52", "C_53", "B_54", "A_55", "B_56", "A_57", "B_58", "B_59", "A_60"]


for(var i=0;i<arr.length;i++){
	let val = arr[i];
	document.getElementById(val).checked = true;
	document.querySelector(".qnav a").click()
}