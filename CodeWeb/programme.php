<?php 
	
	$fichierEtat=fopen('data/etat.json', 'w');
	$etat = $_POST['etat'];
	if($etat == 1){
		fprintf($fichierEtat, '[
	{
		"etat": 0
	}
]
');
	}else{
fprintf($fichierEtat, '[
	{
		"etat": 1
	}
]
');
	}
	fclose($fichierEtat);
?>