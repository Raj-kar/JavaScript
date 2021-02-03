function calculate_bill() {
    var category = document.getElementById("arc").value;
    var meter_number = Number(document.getElementById("meter").value);
    var units = Number(document.getElementById("units").value);
    var total_price = 0;

    if (category === "Agriculture") {
        if (units <= 1000) {
            total_price += units * 5;
        } else {
            total_price += ((1000 * 5) + (units - 1000) * 6);
        }
    } else if (category === "Residential") {
        if (units <= 100) {
            total_price += units * 5;
        } else if (units <= 200) {
            total_price += ((100 * 5) + (units - 100) * 5.5);
        } else if (units <= 300) {
            total_price += ((100 * 5) + (100 * 5.5) + (units - 200) * 6);
        } else if (units <= 400) {
            total_price += ((100 * 5) + (100 * 5.5) + (100 * 6) + (units - 300) * 6.5);
        } else {
            total_price += ((100 * 5) + (100 * 5.5) + (100 * 6) + (100 * 6.5) + (units - 400) * 7);
        }
    } else {
        if (units <= 1000) {
            total_price += units * 8;
        } else {
            total_price += ((1000 * 8) + (units - 1000) * 10) + 1000;
        }
    }

    document.getElementById("output").innerHTML = `User Meter number = ${meter_number} <br> Total bill = ${total_price}`;
}