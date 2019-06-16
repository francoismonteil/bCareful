/*Sparklines */

/* Sparkline plugin Section starts */

$("#status1").sparkline([5,6,7,9,9,5,9,6,5,6,6,7,7,6,7,8,9,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status2").sparkline([5,6,7,4,9,5,9,6,4,6,6,7,8,6,7,4,9,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status3").sparkline([9,6,7,5,9,5,9,7,5,6,3,7,7,6,7,8,8,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status4").sparkline([5,2,7,9,9,4,9,6,5,9,6,7,5,6,7,8,4,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status5").sparkline([7,6,3,9,9,5,4,6,6,9,6,7,7,6,4,8,9,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status6").sparkline([4,6,7,8,9,5,3,6,5,6,7,5,7,2,7,8,7,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

$("#status7").sparkline([3,6,3,9,9,5,4,6,5,6,4,9,7,6,7,8,8,5], {
    type: 'line',
    width: '80',
    height: '20',
    lineColor: '#436B91',
    fillColor: '#fff'});

// graphique

$("#todayspark1").sparkline([8,11,9,12,10,9,13,11,12,11,10,12,11], {
    type: 'bar',
    height: '30',
    barWidth: 5,
    barColor: '#999'});

$("#todayspark2").sparkline([8,11,9,12,10,9,13,11,12,11,10,12,12,11,10,12,11], {
    type: 'bar',
    height: '30',
    barWidth: 5,
    barColor: '#C5CED6'});

$("#todayspark3").sparkline([8,11,9,12,10,9,13,11,12,11,10,12,11,12,11,9], {
    type: 'bar',
    height: '30',
    barWidth: 10,
    barColor: '#436B91'});

$("#todayspark4").sparkline([8,11,9,12,10,9,13,11,12,11,10,12,11,12,11], {
    type: 'bar',
    height: '30',
    barWidth: 10,
    barColor: '#486b60'});

$("#todayspark5").sparkline([10.3,14.2,13.3,7.5,6.3,8.5,9.4,15.25,8.7], {
    type: 'line',
    width: '250',
    height: '30',
    lineColor: '#436B91',
    fillColor: '#efefef'});

$("#todayspark1").update();
$("#todayspark2").update();
$("#todayspark3").update();
$("#todayspark4").update();
$("#todayspark5").update();


/* Sparkline plugin section ends */

