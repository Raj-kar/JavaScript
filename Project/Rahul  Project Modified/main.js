// This function will invoke when user fills all required fields and press Calculate button.
function calculate_bill() {
    // Fetch all user inputs using "getElementById" method.
    var category = document.getElementById("arc").value;
    var meter_number = Number(document.getElementById("meter_no").value);
    var units = Number(document.getElementById("units").value);
    var total_price = 0; // a variable for addup the total cost.

    if (category === "Agriculture") {
        // If user choose category Agriculture
        if (units <= 1000) {
            total_price += units * 5;
        } else {
            total_price += ((1000 * 5) + (units - 1000) * 6);
        }
    } else if (category === "Residential") {
        // If user choose category Residential
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
        // If user choose category Commercial
        if (units <= 1000) {
            total_price += units * 8;
        } else {
            total_price += ((1000 * 8) + (units - 1000) * 10) + 1000;
        }
    }
    // Hold the p tag with "getElementById", and enter data using "innerHTML" method.
    document.getElementById("output").innerHTML = `You have to Pay <b>${total_price}</b> for ${units}units`;
}