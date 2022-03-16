#include "vector.hpp"
#include "Test.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

/* Member types */

/* Member functions */
bool test_default_constructor(void) {
	ft::vector< int > vec;
	if (vec.size() || vec.capacity())
		return (false);
	return (true);
}
bool test_fill_constructor(void) {
	ft::vector< char > vec(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
bool test_range_constructor(void) {
	std::vector< int > stdvec(1, 42);
	stdvec.push_back(43);
	ft::vector< int > vec(stdvec.begin(), stdvec.end());
	if (vec.empty() || vec.capacity() != 2 || vec.at(0) != *(stdvec.begin())
		|| vec.at(1) != *(stdvec.end() - 1))
		return (false);
	return (true);
}
bool test_copy_constructor(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(vec);
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator_reused(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(1, 'b');
	vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator_real(void) {
	std::vector< char > vec(10, 'a');
	std::vector< char > vec2(789888, 'b');
	vec2.push_back('c');
	vec = vec2;
	std::vector< char > ftvec(10, 'a');
	std::vector< char > ftvec2(789888, 'b');
	ftvec2.push_back('c');
	ftvec = ftvec2;
	if (ftvec.capacity() != vec.capacity() || ftvec.size() != vec.size()
		|| vec[0] != ftvec[0] || vec[vec.size() - 1] != ftvec[ftvec.size() - 1])
		return (false);
	return (true);
}
bool test_assign_fill(void) {
	ft::vector< char > vec;
	vec.assign(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2;
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range_reused_bigger(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(100, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 100 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range_reused_smaller(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(1, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_get_allocator(void) {
	assert_eq(std::allocator< char >(), std::vector< char >().get_allocator());
}

/* Access */
bool test_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.at(0);
	assert_eq(c, 'a');
}
bool test_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char& c = vec.at(1);
	assert_eq(c, 'b');
}
bool test_const_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.at(0);
	assert_eq(c, 'a');
}
bool test_const_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const& c = vec.at(1);
	assert_eq(c, 'b');
}
bool test_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec[0];
	assert_eq(c, 'a');
}
bool test_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char& c = vec[1];
	assert_eq(c, 'b');
}
bool test_const_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec[0];
	assert_eq(c, 'a');
}
bool test_const_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const& c = vec[1];
	assert_eq(c, 'b');
}
bool test_front(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.front();
	assert_eq(c, 'a');
}
bool test_const_front(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.front();
	assert_eq(c, 'a');
}
bool test_back(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.back();
	assert_eq(c, 'a');
}
bool test_const_back(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.back();
	assert_eq(c, 'a');
}
bool test_data(void) {
	ft::vector< char > vec(1, 'a');
	char*			   c = vec.data();
	assert_eq(*c, 'a');
}
bool test_const_data(void) {
	ft::vector< char > vec(1, 'a');
	char const*		   c = vec.data();
	assert_eq(*c, 'a');
}

/* Iterators */
bool test_begin(void) {
	assert_eq(*(ft::vector< char >(10, 'a').begin()), 'a');
}
bool test_begin_incremented(void) {
	assert_eq(*(ft::vector< char >(10, 'a').begin() + 1), 'a');
}
bool test_end_decremented(void) {
	assert_eq(*(ft::vector< char >(10, 'a').end() - 1), 'a');
}

/* Capacity */
bool test_empty_true(void) { assert_eq(ft::vector< int >().empty(), true); }
bool test_empty_false(void) {
	assert_eq(ft::vector< char >(10, 'a').empty(), false);
}
bool test_size_null(void) { assert_eq(ft::vector< int >().size(), 0); }
bool test_size_positive(void) {
	assert_eq(ft::vector< char >(10, 'a').size(), 10);
}
bool test_size_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	assert_eq(vec.size(), 9);
}
bool test_max_size(void) {
	assert_eq(ft::vector< int >().max_size(), std::vector< int >().max_size());
}
bool test_reserve(void) {
	ft::vector< char > vec(10, 'a');
	vec.reserve(100);
	if (vec.capacity() != 100 || vec.size() != 10 || vec[0] != 'a'
		|| vec[9] != 'a')
		return (false);
	return (true);
}
bool test_capacity_null(void) { assert_eq(ft::vector< char >().capacity(), 0); }
bool test_capacity_positive(void) {
	assert_eq(ft::vector< char >(10, 'a').capacity(), 10);
}
bool test_capacity_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	assert_eq(vec.capacity(), 10);
}

/* Modifiers */
bool test_clear(void) {
	ft::vector< char > vec(10, 'a');
	vec.clear();
	assert_eq(vec.size(), 0);
}
bool test_insert_simple(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('d');
	vec.push_back('e');
	ft::vector< char >::iterator it = vec.insert(vec.begin() + 2, 'c');
	if (vec.size() != 5 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'd' || vec[4] != 'e'
		|| *it != 'c')
		return (false);
	return (true);
}
bool test_insert_fill(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('d');
	vec.push_back('e');
	vec.insert(vec.begin() + 2, 3, 'c');
	if (vec.size() != 7 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'c' || vec[4] != 'c' || vec[5] != 'd' || vec[6] != 'e')
		return (false);
	return (true);
}
bool test_insert_range(void) {
	std::vector< char > stdvec(1, 'b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	ft::vector< char > vec(1, 'a');
	vec.push_back('e');
	vec.insert(vec.begin() + 1, stdvec.begin(), stdvec.end());
	if (vec.size() != 5 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'd' || vec[4] != 'e')
		return (false);
	return (true);
}
bool test_insert_range_size_one(void) {
	std::vector<char> stdvec(5, 'a');
	ft::vector<char> ftvec(1, 'b');
	ftvec.insert(ftvec.begin(), stdvec.begin(), stdvec.end());
	if (ftvec.size() != 6 || ftvec[0] != 'a' || ftvec[4] != 'a' || ftvec[5] != 'b')
		return (false);
	return (true);
}
bool test_erase_simple(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.erase(vec.begin() + 1);
	if (vec.size() != 2 || vec[0] != 'a' || vec[1] != 'c')
		return (false);
	return (true);
}
bool test_erase_range(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	vec.push_back('e');
	vec.erase(vec.begin() + 1, vec.end() - 1);
	std::vector< char > vec2(1, 'a');
	vec2.push_back('b');
	vec2.push_back('c');
	vec2.push_back('d');
	vec2.push_back('e');
	vec2.erase(vec2.begin() + 1, vec2.end() - 1);
	if (vec.size() != vec2.size() || vec[0] != vec2[0] || vec[1] != vec2[1])
		return (false);
	return (true);
}
bool test_push_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.push_back('b');
	if (vec.size() != 11 || vec[0] != 'a' || vec[10] != 'b')
		return (false);
	return (true);
}
bool test_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	if (vec.size() != 9 || vec[0] != 'a' || vec[8] != 'a')
		return (false);
	return (true);
}
bool test_resize_reduce(void) {
	ft::vector< char > vec(10, 'a');
	vec.resize(1, 'b');
	std::vector< char > stdvec(10, 'a');
	stdvec.resize(1, 'b');
	if (vec.size() != stdvec.size() || vec[0] != stdvec[0])
		return (false);
	return (true);
}
bool test_resize_increase(void) {
	ft::vector< char > vec(10, 'a');
	vec.resize(100, 'b');
	std::vector< char > stdvec(10, 'a');
	stdvec.resize(100, 'b');
	if (vec.size() != stdvec.size() || vec[0] != stdvec[0]
		|| vec[9] != stdvec[0] || vec[10] != stdvec[10]
		|| vec[99] != stdvec[99])
		return (false);
	return (true);
}
bool test_swap(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'b');
	vec.swap(vec2);
	if (vec.size() != 15 || vec[0] != 'b' || vec[14] != 'b' || vec2.size() != 10
		|| vec2[0] != 'a' || vec2[9] != 'a')
		return (false);
	return (true);
}

bool test_vector(void) {
	Test vector_test("Vector");

	/* Member types */

	// vector_test.registerTest("Member types", &test_member_types);

	/* Member functions */
	vector_test.registerTest("Default constructor", &test_default_constructor);
	vector_test.registerTest("Fill constructor", &test_fill_constructor);
	vector_test.registerTest("Range constructor", &test_range_constructor);
	vector_test.registerTest("Copy constructor", &test_copy_constructor);
	vector_test.registerTest("Assignment operator", &test_assignment_operator);
	vector_test.registerTest("Assignment operator reused",
							 &test_assignment_operator_reused);
	vector_test.registerTest("Assignment operator real",
							 &test_assignment_operator_real);
	vector_test.registerTest("Assign fill", &test_assign_fill);
	vector_test.registerTest("Assign range", &test_assign_range);
	vector_test.registerTest("Assign range reuse bigger",
							 &test_assign_range_reused_bigger);
	vector_test.registerTest("Assign range reuse smaller",
							 &test_assign_range_reused_smaller);
	vector_test.registerTest("Get allocator", &test_get_allocator);

	/* Access */
	vector_test.registerTest("At 0", &test_at_single);
	vector_test.registerTest("At 1", &test_at_push_back);
	vector_test.registerTest("Const at 0", &test_const_at_single);
	vector_test.registerTest("Const at 1", &test_at_push_back);
	vector_test.registerTest("Access operator at 0",
							 &test_access_operator_zero);
	vector_test.registerTest("Access operator at 1", &test_access_operator_one);
	vector_test.registerTest("Const access operator at 0",
							 &test_const_access_operator_zero);
	vector_test.registerTest("Const access operator at 1",
							 &test_const_access_operator_one);
	vector_test.registerTest("Front", &test_front);
	vector_test.registerTest("Const front", &test_const_front);
	vector_test.registerTest("Back", &test_back);
	vector_test.registerTest("Const back", &test_const_back);
	vector_test.registerTest("Data", &test_data);
	vector_test.registerTest("Const data", &test_const_data);

	/* Iterators */
	vector_test.registerTest("Begin", &test_begin);
	vector_test.registerTest("Begin incremented", &test_begin_incremented);
	vector_test.registerTest("End decremented", &test_end_decremented);

	/* Capacity */
	vector_test.registerTest("Empty true", &test_empty_true);
	vector_test.registerTest("Empty false", &test_empty_false);
	vector_test.registerTest("Size null", &test_size_null);
	vector_test.registerTest("Size positive", &test_size_positive);
	vector_test.registerTest("Size pop back", &test_size_pop_back);
	vector_test.registerTest("Max size", &test_max_size);
	vector_test.registerTest("Reserve", &test_reserve);
	vector_test.registerTest("Capacity null", &test_capacity_null);
	vector_test.registerTest("Capacity positive", &test_capacity_positive);
	vector_test.registerTest("Capacity pop back", &test_capacity_pop_back);

	/* Modifiers */
	vector_test.registerTest("Clear", &test_clear);
	vector_test.registerTest("Insert simple", &test_insert_simple);
	vector_test.registerTest("Insert fill", &test_insert_fill);
	vector_test.registerTest("Insert range ", &test_insert_range);
	vector_test.registerTest("Insert range size 1", &test_insert_range_size_one);
	vector_test.registerTest("Erase simple", &test_erase_simple);
	vector_test.registerTest("Erase range", &test_erase_range);
	vector_test.registerTest("Push back", &test_push_back);
	vector_test.registerTest("Pop back", &test_pop_back);
	vector_test.registerTest("Resize reduce", &test_resize_reduce);
	vector_test.registerTest("Resize increase", &test_resize_increase);
	vector_test.registerTest("Swap", &test_swap);

	return (vector_test.run());
}
