window.addEventListener('load', function(){
    // add a link to GitHub in the header
    let link = document.getElementsByClassName('page-link')[0];
    link.href = 'https://github.com/sotanishy/competitive-programming-library';
    link.textContent = 'GitHub';

    // remove footer
    document.getElementsByTagName('footer')[0].style.display = 'none';
});