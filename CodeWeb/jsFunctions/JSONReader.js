function sleep(miliseconds){
    var currentTime = new Date().getTime();
    while (currentTime + miliseconds >= new Date().getTime()){

    }
}

function readTextFile(file, callback) {
    var rawFile = new XMLHttpRequest();
    rawFile.overrideMimeType("application/json");
    rawFile.open("GET", file, true);
    rawFile.onreadystatechange = function() {
        if (rawFile.readyState === 4 && rawFile.status == "200") {
            createChartArray(rawFile.responseText);
        }
    }
    rawFile.send(null);
};

function createChartArray(text){
    var data = JSON.parse(text);

    tempArray=[]; tempMoy=0;
    humArray=[]; humMoy=0;
    lumArray=[]; lumMoy=0;
    soundArray=[];

    valueCpt=0;

    data.forEach(element => {
        tempArray.push(element.Temperature); tempMoy+=element.Temperature;
        humArray.push(element.Humidite); humMoy+=element.Humidite;
        lumArray.push(element.Luminosite); lumMoy+=element.Luminosite;
        valueCpt++;
    });
    
    tempMoy=Math.floor(tempMoy/valueCpt);
    humMoy=Math.floor(humMoy/valueCpt);
    lumMoy=Math.floor(lumMoy/valueCpt);
    
    document.getElementById('humId').innerHTML=""+humMoy+"%";
    document.getElementById('tempId').innerHTML=""+tempMoy+"°C";
    document.getElementById('lumId').innerHTML=""+lumMoy+"%";

    console.log(humMoy);
    console.log(tempMoy);
    console.log(lumMoy);

    //return([tempArray, tempMoy, humArray, humMoy, lumArray, lumMoy]);
};

function getEtat(){
    var rawFile = new XMLHttpRequest();
    var etat;
    rawFile.open("GET", "data/etat.json", true);
    rawFile.overrideMimeType("application/json");
    rawFile.onreadystatechange = function() {
        if (rawFile.readyState === 4 && rawFile.status == "200") {
            //state = afficheEtat(rawFile.responseText);
            var text = rawFile.responseText;
            var data = JSON.parse(text);
            etat = data[0].etat;
            if (etat === 1){
                $("#etat").html('<div class="info-box blue-bg">'+
                                    '<i class="fa fa-smile"></i>'+
                                    '<div class="count" id="mode">Mode actuel : &Eacute;veill&eacute;</div>'+
                                '</div>'
                );
            }else{
                $("#etat").html('<div class="info-box dark-bg">'+
                                    '<i class="fa fa-smile"></i>'+
                                    '<div class="count" id="mode">Mode actuel : Endormi</div>'+
                                '</div>'
                );
            }
            $("#divEtat").html('<input style="display:none" id="valueEtat" value='+etat+'>');
        }
    }
    rawFile.send(null);
};
