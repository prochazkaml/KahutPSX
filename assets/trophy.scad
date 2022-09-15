scale(1.5)
translate([0, 0, -5]) {
    rotate_extrude() polygon([[5, 10], [3, 5], [1, 5], [.8, 1], [4, 1], [5, 0], [0, 0], [0, 10]]);

    translate([0, 0, 8.5])
    cube([12, .5, .5], center = true);

    translate([0, 0, 6.5])
    cube([12, .5, .5], center = true);

    translate([-6, 0, 7.5])
    cube([.5, .5, 2], center = true);

    translate([6, 0, 7.5])
    cube([.5, .5, 2], center = true);
}