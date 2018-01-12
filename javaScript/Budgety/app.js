//BUDGET CONTROLLER
var budgetController = (function() {

        var Expense = function(id, description, value){
            this.id = id;
            this.description = description;
            this.value = value;
            this.percentage = -1;
        };

        Expense.prototype.calcPercentage = function(totalIncome){
            if(totalIncome > 0){
                this.percentage = Math.round((this.value / totalIncome) * 100);
            } else {
                this.percentage = -1;
            }
        };

        Expense.prototype.getPercentage = function(){
            return this.percentage;
        };

        var Income = function(id, description, value){
            this.id = id;
            this.description = description;
            this.value = value;
        };

        var calculateTotal = function(type){
            var sum = 0;
            data.allItems[type].forEach(function(cur){
                sum += cur.value;
            });
            data.totals[type] = sum;
        };

        var data = {
            allItems:{
                exp: [],
                inc: []
            },
            totals: {
                exp: 0,
                inc: 0
            },
            budget: 0,
            percentage: -1
        };

        return {
            addItem: function(type, des, val){
                var newItem, ID;

                //create new id
                if(data.allItems[type].length > 0){
                    ID = data.allItems[type][data.allItems[type].length-1].id + 1;
                }else{
                    ID = 0;
                }

                //create new item depending on type
                if (type === 'exp'){
                    newItem = new Expense(ID, des, val);
                } else if(type === 'inc'){
                    newItem = new Income(ID, des, val);
                }

                //add to data structure
                data.allItems[type].push(newItem);

                //return new element
                return newItem;
            },

            deleteItem: function(type, id){
                var ids, index;

                //create area of ids
                ids = data.allItems[type].map(function(current){
                    return current.id;
                });
                
                //find index of our id
                index = ids.indexOf(id);

                if (index !== -1){
                    //remove id from original array
                    data.allItems[type].splice(index, 1);
                }
            },

            calculateBudget: function (){

                // calculate total income and expenese
                calculateTotal('exp');
                calculateTotal('inc');

                //calculate the budget: income - expenses
                data.budget = data.totals.inc - data.totals.exp;

                //calculate the percentage of income that we spent
                if (data.totals.inc > 0){
                data.percentage = Math.round((data.totals.exp / data.totals.inc) * 100);
                } else{
                    data.percentage = -1;
                }
            },

            calculatePercentages: function(){
                data.allItems.exp.forEach(function(current){
                    current.calcPercentage(data.totals.inc);
                });
            },

            getPercentages: function(){
                var allPercentages = data.allItems.exp.map(function(current){
                    return current.getPercentage();
                });
                return allPercentages;
            },

            getBudget: function(){
                return{
                    budget: data.budget,
                    totalInc: data.totals.inc,
                    totalExp: data.totals.exp,
                    percentage: data.percentage
                };
            },

            testing: function(){
                console.log(data);
            }
        };
})();

//UI CONTROLLER
var UIController = (function () {

        var DOMstrings = {
            inputType: '.add__type',
            inputDescription: '.add__description',
            inputValue: '.add__value',
            inputBtn: '.add__btn',
            incomeContainer: '.income__list',
            expensesContainer: '.expenses__list',
            budgetLabel: '.budget__value',
            incomeLabel: '.budget__income--value',
            expeneseLabel: '.budget__expenses--value',
            percentageLabel: '.budget__expenses--percentage',
            container: '.container',
            expensesPercentageLabel: '.item__percentage',
            dateLabel: '.budget__title--month'
        };

        var formatNumber = function(num, type){
            var numSplit, int, dec;

            num = Math.abs(num);
            num = num.toFixed(2);

            numSplit = num.split('.');
            int = numSplit[0];
            dec = numSplit[1];

            if(int.length > 3){
                int = int.substr(0, int.length-3) + ',' + int.substr(int.length - 3);
            }

            

            return (type === 'exp' ? '-' : '+') + ' ' + int + '.' + dec;
        };

        var nodeListForEach = function(list, callback){
            for (var i = 0; i < list.length; i++){
                callback(list[i], i);
            }
        };

        //Public Functions
        return{
            //Gets Inputs from The Fields
            getInput: function(){
                return{
                    type: document.querySelector(DOMstrings.inputType).value,  //either inc or exp
                    description: document.querySelector(DOMstrings.inputDescription).value,
                    value: parseFloat(document.querySelector(DOMstrings.inputValue).value)
                }
            },

            addListItem: function(obj, type){
                var html, newHtml, element;

                // inc or exp
                if (type === 'inc'){
                    element = DOMstrings.incomeContainer;

                    html = '<div class="item clearfix" id="inc-%id%"><div class="item__description">%description%</div><div class="right clearfix"><div class="item__value"> %value%</div><div class="item__delete"><button class="item__delete--btn"><i class="ion-ios-close-outline"></i></button></div></div></div>'
                }else if (type === 'exp'){
                    element = DOMstrings.expensesContainer;

                    html = '<div class="item clearfix" id="exp-%id%"><div class="item__description">%description%</div><div class="right clearfix"><div class="item__value"> %value%</div><div class="item__percentage">%Percentage%</div><div class="item__delete"><button class="item__delete--btn"><i class="ion-ios-close-outline"></i></button></div></div></div>'
                }

                //Replace Placeholder Info
                newHtml = html.replace('%id%', obj.id);
                newHtml = newHtml.replace('%description%', obj.description);
                newHtml = newHtml.replace('%value%', formatNumber(obj.value, type));

                //insert HTML into DOM
                document.querySelector(element).insertAdjacentHTML('beforeend', newHtml);

            },

            deleteListItem: function(selectorId){

                var el = document.getElementById(selectorId);
                el.parentNode.removeChild(el);

            },

            clearFields: function(){
                var fields, fieldsArr;

                fields = document.querySelectorAll(DOMstrings.inputDescription + ', ' + DOMstrings.inputValue);
                fieldsArr = Array.prototype.slice.call(fields);
                fieldsArr.forEach(function(current, index, array){
                    current.value = ""
                });
                fieldsArr[0].focus();
            },

            displayBudget: function(obj){

                //Top inc and exp bars
                var type;
                obj.budget > 0 ? type = 'inc' : type = 'exp';
                document.querySelector(DOMstrings.incomeLabel).textContent = formatNumber(obj.totalInc, 'inc');
                document.querySelector(DOMstrings.expeneseLabel).textContent = formatNumber(obj.totalExp, 'exp');
                
                // sets the + or - sign infront of the input
                if (obj.budget > 0){
                    document.querySelector(DOMstrings.budgetLabel).textContent = formatNumber(obj.budget, type);
                }else{
                    document.querySelector(DOMstrings.budgetLabel).textContent = formatNumber(obj.budget, type);
                }

                //checks for a percentage
                if (obj.percentage > 0){
                    document.querySelector(DOMstrings.percentageLabel).textContent = obj.percentage + '%';
                }else{
                    document.querySelector(DOMstrings.percentageLabel).textContent = '---';
                }
            },

            displayPercentages: function(percentages){

                var fields = document.querySelectorAll(DOMstrings.expensesPercentageLabel);

                nodeListForEach(fields, function(current, index){
                    if(percentages[index] > 0){
                        current.textContent = percentages[index] + '%';
                    } else {
                        current.textContent = '---';
                    }
                });


            },

            displayMonth: function(){

                var now = new Date();

                months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

                document.querySelector(DOMstrings.dateLabel).textContent = months[now.getMonth()] + ', ' + now.getFullYear();

            },

            changedType: function(){

                var fields = document.querySelectorAll(
                    DOMstrings.inputType + ',' +
                    DOMstrings.inputDescription + ','+
                    DOMstrings.inputValue)
                
                    nodeListForEach(fields, function(current){
                        current.classList.toggle('red-focus');
                    });

                    document.querySelector(DOMstrings.inputBtn).classList.toggle('red');

            },

            getDOMstrings: function(){
                return DOMstrings;
            }
        };

})();

// APP CONTROLLER
var controller = (function(budgetCtrl, UICtrl){

    var setupEventListeners = function(){
        var DOM = UICtrl.getDOMstrings();
        document.querySelector(DOM.inputBtn).addEventListener('click', ctrlAddItem);
        
        document.addEventListener('keypress', function(event){
            if(event.keyCode === 13 || event.which === 13){
                ctrlAddItem();
            }
        });

        document.querySelector(DOM.container).addEventListener('click', ctrlDeleteItem);

        document.querySelector(DOM.inputType).addEventListener('change', UICtrl.changedType);
    };

    var updateBudget = function(){

        //1. calculate budget
        budgetCtrl.calculateBudget();

        //2. Return the budget
        var budget = budgetCtrl.getBudget();

        //3. display the budget on the UI
        UICtrl.displayBudget(budget);
    };
    
    var updatePercentages = function(){
        var percentages;

        //1. calculate percentages
        budgetCtrl.calculatePercentages();

        //2. read from budget controller
        percentages = budgetCtrl.getPercentages();

        //3. update UI
        UICtrl.displayPercentages(percentages);
    }

    var ctrlAddItem = function(){
        var input, newItem;

        //1. get input data
        input = UICtrl.getInput();

        // 1.5. Input Validation
        if(input.description !== "" &&  input.value > 0){

            //2. add the item to budgetcontroller
            newItem = budgetCtrl.addItem(input.type, input.description, input.value);
            
            //3. add the item to UI
            UICtrl.addListItem(newItem, input.type);

            //4. clear fields
            UICtrl.clearFields();

            // 5. Calculate and Update budget
            updateBudget();

            //6. calculate and Update Percentages
            updatePercentages();
        }
    };

    var ctrlDeleteItem = function(event){
        var itemId, splitId, type, id;

        //DOM Traversing
        itemId = event.target.parentNode.parentNode.parentNode.parentNode.id;

        if(itemId){
            //breaks up string
            splitId = itemId.split('-');
            type = splitId[0];
            id = parseInt(splitId[1]);

            //1. delete item from data structure
            budgetCtrl.deleteItem(type, id);

            //2. delete item from UI
            UICtrl.deleteListItem(itemId);
            
            //3.update and show the new budget
            updateBudget();
           
            //4. calculate and Update Percentages
            updatePercentages();
        }
    };

    return{
        init: function() {
            UICtrl.displayMonth();
            setupEventListeners();
            UICtrl.displayBudget({
                budget: 0,
                totalInc: 0,
                totalExp: 0,
                percentage: -1
            });
        }
    }

})(budgetController, UIController);

controller.init();