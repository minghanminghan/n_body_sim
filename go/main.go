package main

import (
	"fmt"
	"math"
	"math/rand"
)

type Point struct{ x, y, mass float64 }

// node types: internal vs external
// internal: has no value and 4 children
// external: has no children but has value
type Node struct { // consider oct-tree structure for 3d implementation
	children [4]*Node // node children
	value    *Point   // combined stats
}

func get_center_of_mass(points []*Point) *Point {
	mass, x, y := 0.0, 0.0, 0.0
	for i := 0; i < len(points); i++ {
		mass += points[i].mass
		x += points[i].x * points[i].mass
		y += points[i].y * points[i].mass
	}
	x /= mass
	y /= mass
	p := Point{x, y, mass}
	return &p
}

func (n *Node) better_barnes_hut(points []*Point, width float64, target Point, theta float64) {
	// only children or value
	// 1. check calculated theta vs threshold
	// naive width implementation, could find max distance between 2 points
	com := get_center_of_mass(points)
	distance := math.Pow((math.Pow((com.x-target.x), 2) + math.Pow((com.y-target.y), 2)), 0.5)
	theta_calc := width / distance
	fmt.Printf("com: %f, distance: %f, theta_calc: %f", com, distance, theta_calc)
	// if theta_calc > theta, partition and run the recursive call
}

func (n *Node) barnes_hut(points []*Point) {
	if len(points) > 1 {
		q := len(points) / 4
		r := len(points) % 4
		prev := 0

		for i := 0; i < 4; i++ {
			tmp := q
			if r > 0 {
				tmp++
				r -= 1
			}
			n.children[i] = new(Node)
			n.children[i].barnes_hut(points[prev : prev+tmp])
			prev += tmp
		}
	} else {
		if len(points) > 0 {
			n.value = points[0]
		}
	}
}

func (n *Node) toString(depth int) string {
	out := fmt.Sprintf("%d: ", depth)
	if n.children[0] != nil {
		out += fmt.Sprintf("%#v", n.children)
	} else if n.value != nil {
		out += fmt.Sprintf("%#v", n.value)
	}
	out += "\n"
	for i := 0; i < len(n.children); i++ {
		if n.children[i] != nil {
			out += n.children[i].toString(depth + 1)
		}
	}
	return out
}

func populate_random(points []*Point) {
	for i := 0; i < len(points); i++ {
		point := Point{math.Floor(100*rand.Float64()) / 100, math.Floor(100*rand.Float64()) / 100, 1}
		points[i] = &point
		fmt.Printf("%d: %#v\n", i, points[i])
	}
}

func main() {
	/*
		random_points := [5]*Point{}
		for i := 0; i < len(random_points); i++ {
			point := Point{math.Floor(100*rand.Float64()) / 100, math.Floor(100*rand.Float64()) / 100, 1}
			random_points[i] = &point
		}

		//fmt.Println(random_points)

		start := time.Now()
		root := new(Node)
		root.barnes_hut(random_points[:])
		fmt.Println("constructed quadtree from size", len(random_points), "array in:", time.Since(start))

		start = time.Now()
		fmt.Println(root.toString(0))
		fmt.Println("printed tree in:", time.Since(start))
	*/

	test_points := [10]*Point{}
	populate_random(test_points[:])
	test_slice := test_points[1:]
	test_node := Node{[4]*Node{}, test_points[0]}
	test_node.better_barnes_hut(test_slice, 10, *test_node.value, 1.0)
}

// implement Barnes-Hut algorithm
// 1. given list of nodes, store them in the quad tree using barnes-hut
// 2. compute force acting on each body
