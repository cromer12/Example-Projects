var count = 0;

var arrayImgs = new Array("images/fhp_img1.jpg", "images/fhp_img2.jpg", "images/fhp_img3.jpg", "images/fhp_img4.jpg", "images/fhp_img5.jpg", "images/fhp_img6.jpg", "images/fhp_img7.jpg", "images/fhp_img8.jpg", "images/fhp_img9.jpg", "images/fhp_img10.jpg", "images/fhp_img11.jpg", "images/fhp_img12.jpg", "images/fhp_img13.jpg", "images/fhp_img14.jpg", "images/fhp_img15.jpg", "images/fhp_img16.jpg");

window.onload = function rotate() {

	if (count == arrayImgs.length) {
		count = 0;
	}
	
	document.getElementById("background-id").src = arrayImgs[count];
	
	count++;
	
	setTimeout(rotate, 8000);
}